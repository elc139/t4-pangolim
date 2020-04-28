echo 'População = 64, Experimentos = 150'
echo '1 threads'
export OMP_NUM_THREADS=1,1
time ./omp_virus 64 150 101
echo '2 threads'
export OMP_NUM_THREADS=1,2
time ./omp_virus 64 150 101
echo '4 threads'
export OMP_NUM_THREADS=1,4
time ./omp_virus 64 150 101

echo 'População = 128, Experimentos = 150'
echo '1 threads'
export OMP_NUM_THREADS=1,1
time ./omp_virus 128 150 101
echo '2 threads'
export OMP_NUM_THREADS=1,2
time ./omp_virus 128 150 101
echo '4 threads'
export OMP_NUM_THREADS=1,4
time ./omp_virus 128 150 101

echo 'População = 192, Experimentos = 150'
echo '1 threads'
export OMP_NUM_THREADS=1,1
time ./omp_virus 192 150 101
echo '2 threads'
export OMP_NUM_THREADS=1,2
time ./omp_virus 192 150 101
echo '4 threads'
export OMP_NUM_THREADS=1,4
time ./omp_virus 192 150 101

echo 'População = 20, Experimentos = 5000'
echo '1 threads'
export OMP_NUM_THREADS=1,1
time ./omp_virus 20 5000 101
echo '2 threads'
export OMP_NUM_THREADS=1,2
time ./omp_virus 20 5000 101
echo '4 threads'
export OMP_NUM_THREADS=1,4
time ./omp_virus 20 5000 101

echo 'População = 50, Experimentos = 5000'
echo '1 threads'
export OMP_NUM_THREADS=1,1
time ./omp_virus 50 5000 101
echo '2 threads'
export OMP_NUM_THREADS=1,2
time ./omp_virus 50 5000 101
echo '4 threads'
export OMP_NUM_THREADS=1,4
time ./omp_virus 50 5000 101

echo 'População = 80, Experimentos = 5000'
echo '1 threads'
export OMP_NUM_THREADS=1,1
time ./omp_virus 80 5000 101
echo '2 threads'
export OMP_NUM_THREADS=1,2
time ./omp_virus 80 5000 101
echo '4 threads'
export OMP_NUM_THREADS=1,4
time ./omp_virus 80 5000 101
