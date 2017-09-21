#include <Aria/Aria.h>
#include <ros/ros.h>

// Adds key handler callbacks for controlling the gripper
class GripperControlHandler
{
  ArGripper* myGripper;
  ArFunctorC<GripperControlHandler> myUpCB;
  ArFunctorC<GripperControlHandler> myDownCB;
  ArFunctorC<GripperControlHandler> myOpenCB;
  ArFunctorC<GripperControlHandler> myCloseCB;
  ArFunctorC<GripperControlHandler> myStopCB;
public:
  GripperControlHandler(ArGripper* gripper) :
    myGripper(gripper)
  {
  }


  void liftUp()
  {
    ArLog::log(ArLog::Normal, "Moving gripper lift up...");
    myGripper->liftUp();
  }

  void liftDown()
  {
    ArLog::log(ArLog::Normal, "Moving gripper lift down...");
    myGripper->liftDown();
  }

  void stop()
  {
    ArLog::log(ArLog::Normal, "Stopping gripper...");
    myGripper->gripperHalt(); // stops both lift an grip
    //myGripper->liftStop(); // stops just the lift
    //myGripper->gripStop(); // stops just the gripper
  }

  void close()
  {
    ArLog::log(ArLog::Normal, "Closing gripper...");
    myGripper->gripClose();
  }

  void open()
  {
    ArLog::log(ArLog::Normal, "Opening gripper...");
    myGripper->gripOpen();
  }

};

