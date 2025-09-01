import matplotlib.pyplot as plt

threads = [1, 2, 3, 4]

# Fibonacci Speedup (OpenMP)
speedup_fib = [1, 0.202, 0.187, 0.189]

# Sum (MPI) Speedup
speedup_sum = [1, 2.42, 2.25, 1.61]

plt.figure()
plt.plot(threads, speedup_fib, marker='o', label='Fibonacci (OpenMP)')
plt.plot(threads, speedup_sum, marker='x', label='Sum (MPI)')
plt.xlabel('Threads / Processes')
plt.ylabel('Speedup')
plt.title('Speedup vs Threads/Processes')
plt.grid(True)
plt.legend()
plt.show()

