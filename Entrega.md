# T4: Simulador de Propagação de Vírus com OpenMP

-   **Alunos**: Deivis Costa Pereira e Gustavo Arrua Fantinel.
-   **Disciplina**: ELC139 - Programação Paralela.

## Materiais

### Código

As duas soluções elaboradas se encontram no mesmo arquivo [omp_virus](https://github.com/elc139/t4-pangolim/blob/master/omp_virus/omp_virus.cpp), se distinguem pelos parâmetros e variáveis de ambiente setados.

**Para a Solução 1**: Realiza a execução paralela das funções da classe Population.
```bash
.\omp_virus <tam população> <nro testes> <prob máxima> <nro threads>
``` 
Se preferir, o script [script.sh](omp_virus/script.sh) executará os testes da mesma forma como se encontram nos slides.

**Para a Solução 2**: Mantendo a implementação da Solução 1 explora o uso da função [omp_set_max_active_levels(**2**)](https://computing.llnl.gov/tutorials/openMP/#OMP_SET_MAX_ACTIVE_LEVELS), é necessário exportar a quantidade de threads por nível. 
```bash
export OMP_NUM_THREADS=<nro threads 1º nível>,<nro threads 2º nível>
.\omp_virus <tam população> <nro testes> <prob máxima>
``` 
Se preferir, o script [script2.sh](omp_virus/script2.sh) executará os testes da mesma forma como se encontram nos slides.

### Slides
Os slides com os resultados podem ser encontrados [aqui](slides.pdf).

## Referências
- https://docs.microsoft.com/pt-br/cpp/parallel/openmp/reference/openmp-functions?view=vs-2019
- https://www.openmp.org/wp-content/uploads/omp-hands-on-SC08.pdf
- https://www.ibm.com/developerworks/br/aix/library/au-aix-openmp-framework/index.html
