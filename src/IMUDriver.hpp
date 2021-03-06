#pragma once

#include "Base.hpp"
#include <orocos_cpp_base/ProxyPort.hpp>
#include <base/samples/RigidBodyState.hpp>
#include <base/samples/IMUSensors.hpp>
namespace init
{
    class IMUDriver : public virtual Base
    {
    public:
        IMUDriver(const std::string& name) : Base(name) {};
        virtual ~IMUDriver() {};
        virtual OutputProxyPort<base::samples::RigidBodyState> getOrientationSamples() = 0;
        virtual OutputProxyPort<base::samples::IMUSensors> getSensorSamples() = 0;    
        virtual bool estimate_bias(uint16_t seconds) = 0;
    };
    
}
