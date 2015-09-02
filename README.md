# cmaking
Implementation of a cmake tutorial

Cmake
================================================================================================================

Se trata de una herramienta para la construcción automática de proyectos software, que facilita su portabilidad.

Es una alternativa a las autotools.

En Enigmedia se utiliza un script de configuración para el core linux, que utiliza las autotools para compilar el core, y utiliza cmake para generar un paquete debian (.deb) con los ejecutables y librerías que resultan de la compilación.

 

Como paso previo a realizar posibles modificaciones a dicho script, conviene realizar un pequeño tutorial que permita familiarizarse con la herramienta cmake.

Se ha realizado un proyecto siguiendo el siguiente tutorial de cmake:

http://www.cmake.org/cmake-tutorial/

El proyecto realizado se ha subido al repositorio, porque tener la solución puede facilitar mucho el trabajo de quien quiera realizar el tutorial por primera vez.

Se trata de un programa "Hola Mundo", que se linka con una librería que calcula la raíz cuadrada de un número.

 

Otros tutoriales recomendados:

http://www.linuxhispano.net/2012/11/13/instalar-cmake-con-ejemplo-ubuntu-linu/    (importante leer este)

http://crysol.org/es/node/1342

https://github.com/mgalloy/cpack-cheatsheets/blob/master/cpack-variables.rst

 
Guía detallada

Para compilar y empaquetar el siguiente proyecto software, se deben seguir los siguientes pasos:

    1. Descargar el proyecto del respositorio: https://github.com/rgomezgu/cmaking.git
    2. Colocarse en el directorio raíz y ejecutar los siguientes comandos:
    3. mkdir build
    4. cd build
    5. cmake ..
    6. En este momento se ha generado un programa en build que calcula la raíz cuadrada de un número: ./executable 25
    7. Para generar un paquete ejecutar los siguientes comandos:
    8. cpack --config CPackConfig.cmake
    9. En este momento se ha generado un paquete *.tar.gz en build.
