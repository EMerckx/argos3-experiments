add_library(loop_functions_variable MODULE 
  loop_functions_variable.h
  loop_functions_variable.cpp)

target_link_libraries(loop_functions_variable
  argos3core_simulator
  argos3plugin_simulator_entities
  argos3plugin_simulator_footbot
  argos3plugin_simulator_qtopengl
  ${QT_LIBRARIES} ${GLUT_LIBRARY} ${OPENGL_LIBRARY})