# argos3-experiments

This repository is adapted from the [ilpincy/argos3-examples][1] repository. 

This repository offers experiments that either use C++ or Lua controllers. 
These are separated from each other in different directories.

## Lua experiments

### Using the light sensor

In the [footbot_light_sensor.argos][lua_fb_light_exper] experiment, 
the [light_sensor_controller.lua][lua_fb_light_contr] lets the foot-bot move forward.
Each step it takes, the readings of the light sensors are logged.
The foot-bot stops moving when a given amount of steps are taken.

### Using the omnidirectional camera

In the [footbot_omni_camera.argos][lua_fb_omni_camera_exper] experiment, 
the [omni_camera_controller.lua][lua_fb_omni_camera_contr] looks at the readings
of the omnidirectional camera of the foot-bot.
Each step in the experiment, those readings are logged.
During the experiment, the values remain the same because the robot isn't 
moving around.

[1]: https://github.com/ilpincy/argos3-examples

[lua_fb_light_exper]: https://github.com/EMerckx/argos3-experiments/blob/master/lua_experiments/footbot_light_sensor.argos
[lua_fb_light_contr]: https://github.com/EMerckx/argos3-experiments/blob/master/lua_controllers/light_sensor_controller.lua

[lua_fb_omni_camera_exper]: https://github.com/EMerckx/argos3-experiments/blob/master/lua_experiments/footbot_omni_camera.argos
[lua_fb_omni_camera_contr]: https://github.com/EMerckx/argos3-experiments/blob/master/lua_controllers/omni_camera_controller.lua
