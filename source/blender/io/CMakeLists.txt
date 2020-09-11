add_subdirectory(common)

if(WITH_ALEMBIC)
  add_subdirectory(alembic)
endif()

if(WITH_CODEC_AVI)
  add_subdirectory(avi)
endif()

if(WITH_OPENCOLLADA)
  add_subdirectory(collada)
endif()

if(WITH_USD)
  add_subdirectory(usd)
endif()
