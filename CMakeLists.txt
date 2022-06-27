set(COMPONENT_SRCS "HC4067.cpp")

idf_component_register(SRCS "${COMPONENT_SRCS}"
                    INCLUDE_DIRS "."
                    REQUIRES esp_timer log driver config_global)