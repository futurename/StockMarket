project( stockMarket )
set(SRCS
  Commodities.cpp
	FinancialInstrument.cpp
	Market.cpp
	Player.cpp
	Stock.cpp
  Commodities.cpp
  )
    
set(HEADERS
  Commodities.h
	FinancialInstrument.h
	Market.h
	Player.h
	Stock.h
  Commodities.h
  )
    

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")


# Ask cmake to compile our project into an executable named stockMarket
add_executable( stockMarket main.cpp ${SRCS} ${HEADERS} )
