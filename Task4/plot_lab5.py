import matplotlib.pyplot as plt

threads = [1,2,3,4]

# Fibonacci (OpenMP)
time_fib = [0.002074, 0.010282, 0.011101, 0.010984]
speedup_fib = [1, 0.202, 0.187, 0.189]

# Sum (MPI)
time_sum = [0.030860, 0.012735, 0.013742, 0.019216]
speedup_sum = [1, 2.42, 2.25, 1.61]

# Time vs Threads/Processes
plt.figure()
plt.plot(threads, time_fib, marker='o', label='Fibonacci (OpenMP)')
plt.plot(threads, time_sum, marker='x', label='Sum (MPI)')
plt.xlabel('Threads / Processes')
plt.ylabel('Execution Time (s)')
plt.title('Time vs Threads/Processes')
plt.grid(True)
plt.legend()
plt.show()

# Speedup vs Threads/Processes
plt.figure()
plt.plot(threads, speedup_fib, marker='o', label='Fibonacci (OpenMP)')
plt.plot(threads, speedup_sum, marker='x', label='Sum (MPI)')
plt.xlabel('Threads / Processes')
plt.ylabel('Speedup')
plt.title('Speedup vs Threads/Processes')
plt.grid(True)
plt.legend()
plt.show()

