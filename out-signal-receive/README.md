# The output signal receiving using an FIR filter.
  The FIR filter (also called non-recursive) is a filter whose impulse response contains only a finite number non-zero counts. Such an impulse response is always absolutely we sum, and, therefore, FIR filters are always stable.  
  
  ![](https://latex.codecogs.com/svg.latex?h(n_{1},&space;n_{2})) is the impulse response of the LIS system, has the properties to change the spectrum and therefore can be considered as a filter. Since the capabilities of technical systems are limited, the scope of the filter is limited. This assignment proposes to determine the output of the filter in two ways; using bounded two-dimensional discrete convolution and the method of shift, weighting and summing the impulse response of the LIS-system. When performing two-dimensional convolution, it is necessary to pay attention to the fact that the output signal of the FIR filter has an expanded domain of definition as compared to the input signal. When using the second approach it will turn out automatically.  

  The task presents the impulse response ![](https://latex.codecogs.com/svg.latex?h(n_{1},&space;n_{2})) of the FIR filter and the input signal of the system ![](https://latex.codecogs.com/svg.latex?x(n_{1},&space;n_{2})).

  There is an impulse response of the LIS system ![](https://latex.codecogs.com/svg.latex?h(n_{1},&space;n_{2})). It is necessary to find the response of the system to the input signal ![](https://latex.codecogs.com/svg.latex?x(n_{1},&space;n_{2})) in two ways:
  
  1. using discrete convolution: ![](https://latex.codecogs.com/svg.latex?y(n_{1},&space;n_{2})) = ![](https://latex.codecogs.com/svg.latex?h(n_{1},&space;n_{2})) ** ![](https://latex.codecogs.com/svg.latex?x(n_{1},&space;n_{2}));

  2. by summing the weighted and shifted pulsed feedback.

  ![equation](https://latex.codecogs.com/svg.latex?h(n_1,&space;n_2)&space;=&space;\begin{bmatrix}
&space;3&space;&&space;3&space;&&space;2&space;&&space;2&space;&&space;1&space;&&space;1&space;&&space;2\\
&space;1&space;&&space;1&space;&&space;4&space;&&space;3&space;&&space;2&space;&&space;2&space;&&space;\\
&space;2&space;&&space;2&space;&&space;3&space;&&space;4&space;&&space;&&space;5&space;&&space;4\\
&space;2&space;&&space;4&space;&&space;3&space;&&space;3&space;&&space;2&space;&&space;1&space;&&space;\\
&space;&&space;4&space;&&space;2&space;&&space;&&space;3&space;&&space;6&space;&&space;5\\
&space;&&space;3&space;&&space;2&space;&&space;4&space;&&space;7&space;&&space;5&space;&&space;7\\
&space;&&space;3&space;&&space;3&space;&&space;&&space;4&space;&&space;4&space;&&space;7&space;\end{bmatrix});
  
  ![](https://latex.codecogs.com/svg.latex?x(n_1,&space;n_2)&space;=&space;\begin{bmatrix}&space;&&space;3&space;&&space;3&space;&&space;&&space;5&space;&&space;&&space;\\&space;4&space;&&space;2&space;&&space;2&space;&&space;4&space;&&space;&&space;4&space;&&space;4\\&space;5&space;&&space;3&space;&&space;2&space;&&space;5&space;&&space;3&space;&&space;4&space;&&space;7\\&space;5&space;&&space;4&space;&&space;2&space;&&space;&&space;&&space;4&space;&&space;\\&space;&&space;4&space;&&space;1&space;&&space;4&space;&&space;&&space;&&space;8\\&space;3&space;&&space;3&space;&&space;2&space;&&space;&&space;2&space;&&space;4&space;&&space;5\\&space;&&space;1&space;&&space;3&space;&&space;4&space;&&space;&&space;4&space;&&space;6\\&space;&&space;4&space;&&space;&&space;5&space;&&space;5&space;&&space;&&space;\end{bmatrix});
