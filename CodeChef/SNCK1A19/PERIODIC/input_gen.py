from random import randint

Tp = 10
Ti = 10
with open('input_g', 'w') as fin:
    with open('output_g', 'w') as fout:
        fin.write('{}\n'.format(Tp+Ti+3))

        # possible
        for i in range(Tp):
            N = randint(2, 100)
            K = randint(2, 1000)

            # Gen full seq
            A = []
            for n in range(N):
                for k in range(K):
                    A.append(k + 1)

            # Random trim
            bN = randint(1, K/2)
            del A[-bN:]
            tN = randint(1, K/2)
            del A[:tN]
            print(N, K, tN, bN)

            # Random corp
            cN = randint(1, N)
            for n in range(cN):
                cK = randint(1, K)
                cI = randint(1, len(A))
                for k in range(cK):
                    if (cI + K) >= len(A):
                        break
                    A[cI+k] = -1

            strA = [str(a) for a in A]
            fin.write('{}\n'.format(len(A)))
            fin.write('{}\n'.format(' '.join(strA)))
            fout.write('{}\n'.format(K))

        # inf
        for i in range(Ti):
            N = 1
            K = randint(1, 100)

            # Gen full seq
            A = []
            for k in range(K):
                A.append(k + 1)

            # Random trim
            bN = randint(1, K/2)
            del A[-bN:]
            tN = randint(1, K/2)
            del A[:tN]
            print(N, K, tN, bN)

            # Random corp
            cK = randint(1, K)
            cI = randint(1, len(A))
            for k in range(cK):
                if (cI + K) >= len(A):
                    break
                A[cI+k] = -1

            strA = [str(a) for a in A]
            fin.write('{}\n'.format(len(A)))
            fin.write('{}\n'.format(' '.join(strA)))
            fout.write('inf\n')

        fin.write('3\n')
        fin.write('-1 -1 -1\n')
        fout.write('inf\n')

        fin.write('10\n')
        fin.write('-1 -1 -1 -1 -1 1 2 3 4 5\n')
        fout.write('inf\n')

        fin.write('10\n')
        fin.write('6 7 8 9 10 1 2 3 4 5\n')
        fout.write('10\n')
