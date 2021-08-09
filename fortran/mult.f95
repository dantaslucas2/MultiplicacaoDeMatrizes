
program helloworld
    implicit NONE

    integer :: dimensao
    double precision :: resultado = 0
    integer :: interador1, interador2
    real(8) :: start, finish, tempo1, tempo2


    double precision, dimension(:,:),allocatable :: matriz
    double precision, dimension(:),allocatable :: vetor
    double precision, dimension(:),allocatable :: tot

    do dimensao = 0, 40000, 500
        allocate(matriz(dimensao, dimensao))
        allocate(vetor(dimensao))
        allocate(tot(dimensao))

        ! Inicializar matriz e vetor
        call random_number(matriz) 
        call random_number(vetor) 
        matriz = matriz * 1000000000
        vetor = vetor * 1000000000
        

        call cpu_time(start)

        ! Multiplicando Matriz e vetor
        do interador2 = 1,dimensao
            do interador1 = 1,dimensao
                resultado = (matriz(interador1,interador2) * vetor(interador2)) + resultado
            end do
            tot(interador1) = resultado
            resultado = 0 
        end do

        call cpu_time(finish) 

        tempo1 = (finish - start)
        call cpu_time(start)

        deallocate(tot)
        allocate(tot(dimensao))

        ! Multiplicando Matriz e vetor
        do interador1 = 1,dimensao
            do interador2 = 1,dimensao
                resultado = (matriz(interador1,interador2) * vetor(interador2)) + resultado
            end do
            tot(interador1) = resultado
            resultado = 0 
        end do

        call cpu_time(finish) 

        tempo2 = (finish - start)


        print *,"tempo 1 :", tempo1," tempo 2 : " , tempo2, "dimensao : ", dimensao

        deallocate(matriz)
        deallocate(vetor)
        deallocate(tot)
    end do

end program helloworld