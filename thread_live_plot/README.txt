This is a small demo program showing how data can be sent from a worker thread
to a GUI. It came from

https://github.com/eliben/code-for-blog/tree/master/2009/plotting_data_monitor

and requires PyQt, PyQwt, and PySerial

I synced
extra/python2-pyqt4
community/python2-pyqwt


architecture:
- top-level
  - evolution engine
  - evaluation engine
  - GUI
- knots
  - contains a list of knots
  - can be solved analytically
  - can be used to evaluate the fitness of a genome
- genome
  - contains 4*(number of knots - 1) values
  - fitness can be evaluated based on a set of knots
- population
  - contains a list of genomes
  - can be sorted by fitness
  - can produce a new generation based on ranking
