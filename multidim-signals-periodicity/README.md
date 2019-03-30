    The main difference of multidimensional periodic signals from one-dimensional is that when additional degrees of freedom appear, the signal begins to show the vector properties of periodicity.
    In this regard, the number of periods can reach ![](https://latex.codecogs.com/png.latex?n^{2}), where *n* is the number of measurements.

    The periodicity condition is written as follows:

    <a href="https://www.codecogs.com/eqnedit.php?latex=\\\widetilde{x}(n_{1}&plus;N_{11},n_2&plus;N_{21}])=\widetilde{x}(n_{1},&space;n_{2}),\\&space;\widetilde{x}(n_{1}&plus;N_{12},n_2&plus;N_{22}])=\widetilde{x}(n_{1},&space;n_{2})." target="_blank"><img src="https://latex.codecogs.com/png.latex?\\\widetilde{x}(n_{1}&plus;N_{11},n_2&plus;N_{21}])=\widetilde{x}(n_{1},&space;n_{2}),\\&space;\widetilde{x}(n_{1}&plus;N_{12},n_2&plus;N_{22}])=\widetilde{x}(n_{1},&space;n_{2})." title="\\\widetilde{x}(n_{1}+N_{11},n_2+N_{21}])=\widetilde{x}(n_{1}, n_{2}),\\ \widetilde{x}(n_{1}+N_{12},n_2+N_{22}])=\widetilde{x}(n_{1}, n_{2})," /></a>
    
    where ![](https://latex.codecogs.com/png.latex?N_{ij}) - components of the periodicity vectors. The difficulties also lie in the fact that it is possible to specify the same periodic sequence ambiguously. That is, the components of the vectors can have different numerical values, and denote the same sequence. Therefore, in contrast to one-dimensional sequences, a special study is required to establish the sequence identity. For the initial assessment, you can resort to the calculation of some determinant:
    
    <a href="https://www.codecogs.com/eqnedit.php?latex=\begin{pmatrix}&space;N_{11}\\&space;N_{21}&space;\end{pmatrix},&space;\begin{pmatrix}&space;N_{12}\\&space;N_{22}&space;\end{pmatrix},\\&space;D\overset{\Delta&space;}{=}N_{11}N_{22}-N_{12}N_{21}\not=0" target="_blank"><img src="https://latex.codecogs.com/png.latex?\begin{pmatrix}&space;N_{11}\\&space;N_{21}&space;\end{pmatrix},&space;\begin{pmatrix}&space;N_{12}\\&space;N_{22}&space;\end{pmatrix},\\&space;D\overset{\Delta&space;}{=}N_{11}N_{22}-N_{12}N_{21}\not=0" title="\begin{pmatrix} N_{11}\\ N_{21} \end{pmatrix}, \begin{pmatrix} N_{12}\\ N_{22} \end{pmatrix},\\ D\overset{\Delta }{=}N_{11}N_{22}-N_{12}N_{21}\not=0" /></a>

![](https://github.com/dleliuhin/MDSP/blob/master/multidim-signals-periodicity/desmos-graph.png)
