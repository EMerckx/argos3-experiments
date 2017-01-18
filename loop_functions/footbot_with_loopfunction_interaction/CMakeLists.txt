add_library(footbot_with_loopfunction_interaction MODULE 
  footbot_with_loopfunction_interaction_loopfunctions.h
  footbot_with_loopfunction_interaction_loopfunctions.cpp)

target_link_libraries(footbot_with_loopfunction_interaction
  argos3core_simulator
  argos3plugin_simulator_entities
  argos3plugin_simulator_footbot
  argos3plugin_simulator_qtopengl
  ${QT_LIBRARIES} ${GLUT_LIBRARY} ${OPENGL_LIBRARY})