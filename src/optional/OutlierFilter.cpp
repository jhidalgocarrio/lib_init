#include "OutlierFilter.hpp"

init::OutlierFilter::OutlierFilter(const std::string& taskName, DepthMapProvider &inputp): 
    DepthMapProvider(taskName), 
    input(inputp),
    filterTask(this, taskName)
{
    registerDependency(input);
}

bool init::OutlierFilter::connect()
{
    input.getDepthMapPort().connectTo(filterTask.getConcreteProxy()->depth_map, RTT::ConnPolicy::buffer(20));
    
    return DepthMapProvider::connect();
}

OutputProxyPort< base::samples::DepthMap >& init::OutlierFilter::getDepthMapPort()
{
    return filterTask.getConcreteProxy()->filtered_depth_map;
}
