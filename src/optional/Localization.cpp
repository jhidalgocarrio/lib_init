#include "Localization.hpp"

init::Localization::Localization(const std::string taskName, init::DepthMapProvider& provider): 
    Base("Localization"),
    PositionProvider("Localization"), 
    provider(provider),
    localizer(this, taskName)
{
    registerDependency(provider);
}

bool init::Localization::connect()
{
    provider.getDepthMapPort().connectTo(localizer.getConcreteProxy()->lidar_samples);
    
    return PositionProvider::connect();
}

OutputProxyPort< base::samples::RigidBodyState >& init::Localization::getPositionSamples()
{
    return localizer.getConcreteProxy()->pose_samples;
}

