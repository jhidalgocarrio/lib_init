#pragma once

#include <lib_init/Base.hpp>
#include <lib_init/MotionControl2D.hpp>

namespace safety_control {
     namespace proxies {
         class Task;
     }
}

namespace init
{

class SafetyController : public MotionControl2D
{
protected:
    MotionControl2D &motionControl;

public:
    SafetyController(MotionControl2D& motionControl, const std::string& taskName);
    virtual ~SafetyController();
    virtual bool connect();
    InputProxyPort<base::commands::Motion2D> &getCommand2DPort();
    InputProxyPort<base::commands::Motion2D> &getOverrideCommandPort();

    DependentTask<safety_control::proxies::Task> safetyControlTask;
};
}