add_library(loop_functions_log_float_number MODULE 
  loop_functions_log_float_number.h
  loop_functions_log_float_number.cpp)

target_link_libraries(loop_functions_log_float_number
  argos3core_simulator
  argos3plugin_simulator_entities
  argos3plugin_simulator_footbot
  argos3plugin_simulator_qtopengl
  ${QT_LIBRARIES} ${GLUT_LIBRARY} ${OPENGL_LIBRARY})