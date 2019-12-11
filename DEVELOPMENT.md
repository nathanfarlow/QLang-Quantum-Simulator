- **11/21/19** Began work on matrix library
   - Added matrix skeleton
   - Designed method of matrix processing
      - Still need to actually implement the processing part, but the abstraction is there

During the week of Thanksgiving break, I finished my reading of Quantum Computing for Computer Scientists by Noson S. Yanofsky.

- **12/2/19** Finish default matrix library
   - Implemented the big 5 for the matrix class
   - Implemented matrix naive multiplication, addition, subtraction, and tensor product on CPU
      - Nothing is run on GPU yet
   - Implemented unit and integration testing for matrix operations and memory management
   
- **12/3/19** Define OpenCL processor
   - Using my abstraction for matrix processing, I added a definition for an OpenCL matrix processor
      - Nothing is actually processed yet
   - Added tests for the OpenCL processor

- **12/4/19** Implement OpenCL processor functionality and completely refactor matrix library
   - Completely restructured the matrix storage approach due to OpenCL needing data stored in consecutive parts of memory
      - Had to spend a lot of time debugging after this refactoring, but unit tests helped
   - Designed the OpenCL processor that loads an OpenCL kernel
   - Implemented the OpenCL kernel
      - Kerenel uses a very naive technique and is not very efficent, maybe we could revisit this later
   - Add more OpenCL tests
   
- **12/9/19** Add quantum initial definitions and operations
   - Implemented computation of unary gates
      - Fixed tensor product bugs found through this process
   - Added testing for unary gates
   
- **12/10/19** Begin and finish QLang parser
   - Implemented binary quantum gate computation support
      - This was much more difficult than I expected. To support arbitrary qubits, I use several (at worst, n) swap operations to position qubits to then apply the gate, then swap them back to their original positions. Together, this makes the entire application of a binary gate n^4 for an n qubit circuit. This is very inefficient.
      - Added testing for binary gates
   - Implememented QLang parsing
   - Created GUI
   - Some project refactoring
   
- **12/11/19** Touch-ups before presentation
   - Created readme
   - Ensured circuit cannot be declared twice
   - Refactored source files into their respective folders
   - Change GUI font to monospace
   
