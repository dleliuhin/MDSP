# Anisotropic and threshold statistical filtering methods.
  
  ## Anisotropic filtering method.

  This method is based on using convolution of the original image array <img src="https://latex.codecogs.com/gif.latex?f(n_1,&space;n_2)" title="f(n_1, n_2)" /> of size <img src="https://latex.codecogs.com/gif.latex?M*M" title="M*M" /> with a smoothing array size <img src="https://latex.codecogs.com/gif.latex?N*N" title="N*N" />. When <img src="https://latex.codecogs.com/gif.latex?N<<M" title="N<<M" /> software scanning is implemented of array <img src="https://latex.codecogs.com/gif.latex?f(n_1,&space;n_2)" title="f(n_1, n_2)" /> by some array <img src="https://latex.codecogs.com/gif.latex?W(m_1,&space;m_2)" title="W(m_1, m_2)" /> of dimension <img src="https://latex.codecogs.com/gif.latex?N*N" title="N*N" /> and
  convolution operation at each step. As a result, a new array <img src="https://latex.codecogs.com/gif.latex?g(n_1,&space;n_2)" title="g(n_1, n_2)" /> of a smoothed image is formed, having a size of <img src="https://latex.codecogs.com/gif.latex?M*M" title="M*M" />. Such an algorithm is convenient for implementation on a computer. For each element <img src="https://latex.codecogs.com/gif.latex?f(i,j)" title="f(i,j)" /> of the original array <img src="https://latex.codecogs.com/gif.latex?f(n_1,&space;n_2)" title="f(n_1, n_2)" />, a transformation is performed, which consists in multiplying the matrix framing it of a given size <img src="https://latex.codecogs.com/gif.latex?N*N" title="N*N" /> with the smoothing elements.

  Subsequent summation of works gives the elements of output array:

  <img src="https://latex.codecogs.com/gif.latex?g(i,j)=\sum_{k=-\frac{N-1}{2}}^{&plus;\frac{N-1}{2}}&space;\sum_{l=-\frac{N-1}{2}}^{&plus;\frac{N-1}{2}}&space;f(i&plus;k,j&plus;l)*W(k,l)." title="g(i,j)=\sum_{k=-\frac{N-1}{2}}^{+\frac{N-1}{2}} \sum_{l=-\frac{N-1}{2}}^{+\frac{N-1}{2}} f(i+k,j+l)*W(k,l)." />

  The array elements are numerical values corresponding to the brightness. We should also dwell on the construction of a smoothing array.

  The quality of filtering increases with increasing <img src="https://latex.codecogs.com/gif.latex?N" title="N" />, however, in proportion to <img src="https://latex.codecogs.com/gif.latex?N^{2}" title="N^{2}" />, the processing time of the original image on a computer increases, and important details of the image itself that have a high-frequency component may disappear, so the choice of <img src="https://latex.codecogs.com/gif.latex?N" title="N" /> is a compromise and is determined by the optimal image quality. The array <img src="https://latex.codecogs.com/gif.latex?W" title="W" /> must be normalized to obtain a unit transfer coefficient so that the average brightness of the image does not change during filtering. The following smoothing arrays <img src="https://latex.codecogs.com/gif.latex?W" title="W" /> can be used.

  For isotropic filtering:

  <img src="https://latex.codecogs.com/gif.latex?\frac{1}{9}&space;\bigl(\begin{smallmatrix}&space;1&space;&&space;1&space;&&space;1\\&space;1&space;&&space;1&space;&&space;1\\&space;1&space;&&space;1&space;&&space;1&space;\end{smallmatrix}\bigr)" title="\frac{1}{9} \bigl(\begin{smallmatrix} 1 & 1 & 1\\ 1 & 1 & 1\\ 1 & 1 & 1 \end{smallmatrix}\bigr)" /> or <img src="https://latex.codecogs.com/gif.latex?\frac{1}{10}&space;\bigl(\begin{smallmatrix}&space;1&space;&&space;1&space;&&space;1\\&space;1&space;&&space;2&space;&&space;1\\&space;1&space;&&space;1&space;&&space;1&space;\end{smallmatrix}\bigr)" title="\frac{1}{10} \bigl(\begin{smallmatrix} 1 & 1 & 1\\ 1 & 2 & 1\\ 1 & 1 & 1 \end{smallmatrix}\bigr)" /> and others.

  For anisotropic filtering:

  <img src="https://latex.codecogs.com/gif.latex?\frac{1}{16}&space;\bigl(\begin{smallmatrix}&space;1&space;&&space;2&space;&&space;1\\&space;2&space;&&space;4&space;&&space;2\\&space;1&space;&&space;2&space;&&space;1&space;\end{smallmatrix}\bigr)" title="\frac{1}{16} \bigl(\begin{smallmatrix} 1 & 2 & 1\\ 2 & 4 & 2\\ 1 & 2 & 1 \end{smallmatrix}\bigr)" /> etc.

  ## Statistical filtering method.

  This filtering method can be called the adaptive threshold filtering method. When implementing it, the digital representation of the brightness of all elements of the image is sequentially checked <img src="https://latex.codecogs.com/gif.latex?f(x,y)-f(n_{1},n_{2})" title="f(x,y)-f(n_{1},n_{2})" />. Analyzed a group of <img src="https://latex.codecogs.com/gif.latex?N*N" title="N*N" /> elements, where <img src="https://latex.codecogs.com/gif.latex?N\geq&space;3" title="N\geq 3" /> and <img src="https://latex.codecogs.com/gif.latex?N" title="N" /> is odd.

  The value of the first moment for these elements is calculated:

  <img src="https://latex.codecogs.com/gif.latex?g(i,j)=\frac{1}{N^{2}}&space;\sum_{k=-\frac{N-1}{2}}^{\frac{N-1}{2}}&space;\sum_{l=-\frac{N-1}{2}}^{\frac{N-1}{2}}&space;f(i&plus;k,j&plus;l)" title="g(i,j)=\frac{1}{N^{2}} \sum_{k=-\frac{N-1}{2}}^{\frac{N-1}{2}} \sum_{l=-\frac{N-1}{2}}^{\frac{N-1}{2}} f(i+k,j+l)" />,

  and then the second moment and standard deviation, the value of which is used to obtain the threshold value <img src="https://latex.codecogs.com/gif.latex?\eta&space;(i,j)=m*\sigma&space;(i,j)" title="\eta (i,j)=m*\sigma (i,j)" />, where 

  <img src="https://latex.codecogs.com/gif.latex?D(i,j)=&space;\frac{1}{N^{2}-1}*&space;\sum_{k=-\frac{N-1}{2}}^{\frac{N-1}{2}}&space;\sum_{l=-\frac{N-1}{2}}^{\frac{N-1}{2}}&space;(f(i&plus;k,j&plus;l)-g(i,j))^{2}" title="D(i,j)= \frac{1}{N^{2}-1}* \sum_{k=-\frac{N-1}{2}}^{\frac{N-1}{2}} \sum_{l=-\frac{N-1}{2}}^{\frac{N-1}{2}} (f(i+k,j+l)-g(i,j))^{2}" />,

  <img src="https://latex.codecogs.com/gif.latex?\sigma&space;(i,j)=\sqrt{D(i,j)}," title="\sigma (i,j)=\sqrt{D(i,j)}," />,

  m depends on the nature of the image being analyzed, that is, on the value of the high-frequency components in the signal spectrum and on the required contrast value (in practice, m is obtained experimentally by solving a particular problem).

  If <img src="https://latex.codecogs.com/gif.latex?\left&space;|&space;f(i,j)-g(i,j)&space;\right&space;|&space;\leq&space;m*\sigma&space;(i,j)" title="\left | f(i,j)-g(i,j) \right | \leq m*\sigma (i,j)" />, то <img src="https://latex.codecogs.com/gif.latex?f(i,j)=f(i,j)" title="f(i,j)=f(i,j)" />, otherwise 

  <img src="https://latex.codecogs.com/gif.latex?f(i,j)=\frac{1}{N^{2}-1}*(\sum_{k=-\frac{N-1}{2}}^{&plus;\frac{N-1}{2}}&space;\sum_{l=-\frac{N-1}{2}}^{-1}&space;f(i&plus;k,j&plus;l)&plus;\sum_{k=&plus;1}^{\frac{N-1}{2}}f(i&plus;k,j))&plus;(\sum_{k=-\frac{N-1}{2}}^{\frac{N-1}{2}}&space;\sum_{l=&plus;1}^{\frac{N-1}{2}}&space;f(i&plus;k,j&plus;l)&plus;\sum_{k=-\frac{N-1}{2}}^{-1}&space;f(i&plus;k,j))" title="f(i,j)=\frac{1}{N^{2}-1}*(\sum_{k=-\frac{N-1}{2}}^{+\frac{N-1}{2}} \sum_{l=-\frac{N-1}{2}}^{-1} f(i+k,j+l)+\sum_{k=+1}^{\frac{N-1}{2}}f(i+k,j))+(\sum_{k=-\frac{N-1}{2}}^{\frac{N-1}{2}} \sum_{l=+1}^{\frac{N-1}{2}} f(i+k,j+l)+\sum_{k=-\frac{N-1}{2}}^{-1} f(i+k,j))" />, usually N = 3, 5, 7.
