Zum Kompilieren mit Cython:

1. Cython installieren (pip install cython)
2. cython windowmain.pyx (dieser Befehl erstellt windowmain.c)
2. per gcc:     gcc -c -I"[python include dir]" -o windowmain windowmain.c

[python include dir] ist im jeweiligen Python-Installationsordner zu finden.
