add_library(empty_loop_functions MODULE 
  empty_loop_functions.h
  empty_loop_functions.cpp)

target_link_libraries(empty_loop_functions
  argos3core_simulator
  argos3plugin_simulator_entities
  argos3plugin_simulator_footbot
  argos3plugin_simulator_qtopengl
  ${QT_LIBRARIES} ${GLUT_LIBRARY} ${OPENGL_LIBRARY})