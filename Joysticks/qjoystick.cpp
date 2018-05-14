#include "qjoystick.h"

QJoystick::QJoystick()
{
    // Sure, we're only using the Joystick, but SDL doesn't work if video isn't initialised
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK);
    mJoystick = NULL;   //js not opened yet
}

QJoystick::~QJoystick()
{
    SDL_JoystickClose(mJoystick);
    SDL_QuitSubSystem(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK);
}

void QJoystick::init()
{
    Q_ASSERT(currentJoystick() >= 0);
    Q_ASSERT(currentJoystick() < numJoysticks());

    mJoystick  = SDL_JoystickOpen(currentJoystick());
    QJoystickInterface::init();
}

QString QJoystick::name() const
{
    return QString(SDL_JoystickName(currentJoystick()));
}

int QJoystick::numAxes() const
{
    int ret = -1;
    if(mJoystick != NULL)
    {
        ret = SDL_JoystickNumAxes(mJoystick);
    }

    return ret;
}

int QJoystick::numButtons() const
{
    int ret = -1;
    if(mJoystick != NULL)
    {
        ret = SDL_JoystickNumButtons(mJoystick);
    }

    return ret;
}

int QJoystick::numHats() const
{
    int ret = -1;
    if(mJoystick != NULL)
    {
        ret = SDL_JoystickNumHats(mJoystick);
    }

    return ret;
}

int QJoystick::reenumerateDevices()
{
    SDL_QuitSubSystem(SDL_INIT_JOYSTICK);   //Quit the subsystem
    SDL_Init(SDL_INIT_JOYSTICK);    //Re-open the subsystem (also reenumerate devices)

    return SDL_NumJoysticks();  //return the number of attached joysticks
}

int QJoystick::numJoysticks() const
{
     return SDL_NumJoysticks();
}

void QJoystick::getData()
{
    SDL_Event event;
    SDL_PollEvent(&event);

    for(int i=0;i<numButtons();i++)
    {
        mButtonsCurrent[i] = SDL_JoystickGetButton(mJoystick, i);

        //check if button was pressed
        if(mButtonsCurrent[i] == true && mButtonsPrevious[i] == false)
        {
            emit buttonPressed(i);
        }

        //check if button was released
        else if(mButtonsCurrent[i] == false && mButtonsPrevious[i] == true)
        {
            mButtonsToggled[i] = !mButtonsToggled[i];
            emit buttonToggled(i, mButtonsToggled[i]);
            emit buttonReleased(i);
        }

        mButtonsPrevious[i] = mButtonsCurrent[i];
    }

    for(int i=0;i<numHats(); i++)
    {
        int hat = SDL_JoystickGetHat(mJoystick, i);
        hat = mapHatDirection(hat);
        if(!mHatsCurrent[i].contains(hat))
        {
            mHatsCurrent[i].insert(hat, true);
            mHatsPrevious[i].insert(hat, false);
            mHatsToggled[i].insert(hat, true);
        }

        QMapIterator<int, bool> it(mHatsCurrent[i]);
        while(it.hasNext())
        {
            it.next();

            //Record current key press
            mHatsCurrent[i][it.key()] = (hat == it.key() ? true : false);

            //Check values
            if(mHatsCurrent[i][it.key()] && !mHatsPrevious[i][it.key()])
            {
                emit hatPressed(i, it.key());
            }
            else if(!mHatsCurrent[i][it.key()] && mHatsPrevious[i][it.key()])
            {
                emit hatToggled(i, it.key(), mHatsToggled[i][it.key()]);
                mHatsToggled[i][it.key()] = !mHatsToggled[i].value(it.key());
                emit hatReleased(i, it.key());
            }

            mHatsPrevious[i][it.key()] = mHatsCurrent[i][it.key()];
        }
    }

    for(int i=0;i<numAxes();i++)
    {
        mAxesCurrent[i] = SDL_JoystickGetAxis(mJoystick, i);
    }

    //Process axis data
    processDeadzones();
    processBilinear();

    emit axesUpdated(mAxesCurrent);
}

QJoystickInterface::HatDirection QJoystick::mapHatDirection(int sdldir)
{
    QJoystickInterface::HatDirection hat = Center;
    switch(sdldir)
    {
    case SDL_HAT_CENTERED:
        hat = Center;
        break;

    case SDL_HAT_UP:
        hat = Up;
        break;

    case SDL_HAT_RIGHT:
        hat = Right;
        break;

    case SDL_HAT_DOWN:
        hat = Down;
        break;

    case SDL_HAT_LEFT:
        hat = Left;
        break;

    case SDL_HAT_RIGHTUP:
        hat = RightUp;
        break;

    case SDL_HAT_RIGHTDOWN:
        hat = RightDown;
        break;

    case SDL_HAT_LEFTUP:
        hat = LeftUp;
        break;

    case SDL_HAT_LEFTDOWN:
        hat = LeftDown;
        break;
    }
    return hat;
}
