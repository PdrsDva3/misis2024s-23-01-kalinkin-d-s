#-----------------------COMPLEX--------------------------
add_executable(test_complex test_complex.cpp)
target_link_libraries(test_complex complex)

#-----------------------RATIONAL--------------------------
add_executable(test_rational test_rational.cpp)
target_link_libraries(test_rational rational)

#-----------------------STACK-----------------------------
add_executable(test_stackarr test_stackarr.cpp)
target_link_libraries(test_stackarr stackarr complex)

add_executable(test_stacklst test_stacklst.cpp)
target_link_libraries(test_stacklst stacklst complex)

#templates
add_executable(test_stackarrt test_stackarrt.cpp)
target_link_libraries(test_stackarrt stackarrt)

add_executable(test_stacklstt test_stacklstt.cpp)
target_link_libraries(test_stacklstt stacklstt)

#-----------------------QUEUE------------------------------
add_executable(test_queuelst test_queuelst.cpp)
target_link_libraries(test_queuelst queuelst complex)

add_executable(test_queuelstpr test_queuelstpr.cpp)
target_link_libraries(test_queuelstpr queuelstpr)

add_executable(test_queuearr test_queuearr.cpp)
target_link_libraries(test_queuearr queuearr)

#templates
add_executable(test_queuearrt test_queuearrt.cpp)
target_link_libraries(test_queuearrt queuearrt)

add_executable(test_queuelstt test_queuelstt.cpp)
target_link_libraries(test_queuelstt queuelstt)
