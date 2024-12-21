        int base, row, column, temp;

        main()
        {

            do
            {
                 system("cls");
                 printf("Enter the number of rows: ");
                 scanf("%d", &base);
            } while ((base<0) || (base>20));

            //Output Area
            temp=(2*base)-1;
            for (row=1;row<=temp;row++)

                {
                for (column=1;column<=temp;column++)
                {
                  if ((row<=base) && ((column==((base-1)+row)) || (column==((base+1)-row)))) //upper half of the triangle
                         printf("*",column);
                  else
                      printf(" ");
                }

                printf("\n");
             }

             return 0;
        }
