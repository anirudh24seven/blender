set(INC
  .
  intern
  ../blenkernel
  ../blenlib
  ../depsgraph
  ../functions
  ../imbuf
  ../makesdna
  ../makesrna
  ../nodes
  ../../../intern/guardedalloc
)

set(INC_SYS
  ${EIGEN3_INCLUDE_DIRS}
)

set(SRC
  intern/SIM_mass_spring.cpp
  intern/hair_volume.cpp
  intern/implicit_blender.c
  intern/implicit_eigen.cpp
  intern/particle_allocator.cc
  intern/particle_function.cc
  intern/particle_mesh_emitter.cc
  intern/simulation_collect_influences.cc
  intern/simulation_solver.cc
  intern/simulation_solver_influences.cc
  intern/simulation_update.cc

  intern/ConstrainedConjugateGradient.h
  intern/eigen_utils.h
  intern/implicit.h
  intern/particle_allocator.hh
  intern/particle_function.hh
  intern/particle_mesh_emitter.hh
  intern/simulation_collect_influences.hh
  intern/simulation_solver.hh
  intern/simulation_solver_influences.hh
  intern/time_interval.hh

  SIM_mass_spring.h
  SIM_simulation_update.hh
)

set(LIB
  bf_blenkernel
  bf_nodes
)

if(WITH_OPENMP_STATIC)
  list(APPEND LIB
    ${OpenMP_LIBRARIES}
  )
endif()

blender_add_lib(bf_simulation "${SRC}" "${INC}" "${INC_SYS}" "${LIB}")
