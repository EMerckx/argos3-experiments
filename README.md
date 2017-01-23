# argos3-experiments

This repository is adapted from the [ilpincy/argos3-examples][1] repository. 

This repository offers experiments that either use C++ or Lua controllers. 
These are separated from each other in different directories.

## Lua experiments

### Hello world

To start off, a little experiment where the foot-bot logs "Hello world." on each step.
The [footbot_hello_world.argos][lua_fb_hello_world_exper] experiment uses the following 
Lua controller: [hello_world_controller.lua][lua_fb_hello_world_contr].

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

### Using the LED actuator

In the [footbot_led.argos][lua_fb_led_exper] experiment, 
the [led_controller.lua][lua_fb_led_contr] uses the LEDs of the robot.
Each step in the experiment, a new color is chosen and set to the leds.

The visualization of the experiment can be viewed in 
[the led actuator movie][yt_fb_led_exper].

[1]: https://github.com/ilpincy/argos3-examples

[lua_fb_hello_world_exper]: https://github.com/EMerckx/argos3-experiments/blob/master/lua_experiments/footbot_hello_world.argos
[lua_fb_hello_world_contr]: https://github.com/EMerckx/argos3-experiments/blob/master/lua_controllers/hello_world_controller.lua

[lua_fb_light_exper]: https://github.com/EMerckx/argos3-experiments/blob/master/lua_experiments/footbot_light_sensor.argos
[lua_fb_light_contr]: https://github.com/EMerckx/argos3-experiments/blob/master/lua_controllers/light_sensor_controller.lua

[lua_fb_omni_camera_exper]: https://github.com/EMerckx/argos3-experiments/blob/master/lua_experiments/footbot_omni_camera.argos
[lua_fb_omni_camera_contr]: https://github.com/EMerckx/argos3-experiments/blob/master/lua_controllers/omni_camera_controller.lua

[lua_fb_led_exper]: https://github.com/EMerckx/argos3-experiments/blob/master/lua_experiments/footbot_led.argos
[lua_fb_led_contr]: https://github.com/EMerckx/argos3-experiments/blob/master/lua_controllers/led_controller.lua
[yt_fb_led_exper]: https://youtu.be/XDcynzxLT_o
