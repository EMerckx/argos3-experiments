add_library(eyebot_diffusion MODULE eyebot_diffusion.h eyebot_diffusion.cpp)
target_link_libraries(eyebot_diffusion
  argos3core_simulator
  argos3plugin_simulator_eyebot
  argos3plugin_simulator_genericrobot)
