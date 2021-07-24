# location of the Python header files
PYTHON_VERSION = 27
PYTHON_DOT_VERSION = 2.7
PYTHON_INCLUDE = /usr/include/python$(PYTHON_DOT_VERSION)
# location of the Boost Python include files and library
BOOST_INC = /usr/local/boost_1_76_0
BOOST_LIB = /usr/local/boost_1_76_0/stage/lib
# compile mesh classes
TARGET = hello_ext
$(TARGET).so: $(TARGET).o
	g++ -shared -Wl,--export-dynamic $(TARGET).o -L$(BOOST_LIB) -lboost_python$(PYTHON_VERSION) -L/usr/lib/python$(PYTHON_DOT_VERSION)/config-x86_64-linux-gnu -lpython$(PYTHON_DOT_VERSION) -o $(TARGET).so
$(TARGET).o: $(TARGET).cpp
	g++ -I$(PYTHON_INCLUDE) -I$(BOOST_INC) -fPIC -c $(TARGET).cpp
