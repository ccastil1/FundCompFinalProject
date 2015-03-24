{

     printf("Enter 'a' to add a new live cell; 'r' to remove a cell; 'n' to advance the simulation to the next iteration;'q' to quit the program; or 'p' to
 play the game continuously.\n");

	printf("Enter your choice: ");
        scanf("%c", &choice);

	char choice;

        if(choice == 'a')
        {
                printf("Enter coordinates for the new cell: ");
                scanf("%d %d", &x, &y);

                newcell(x, y, board);
        }

	if(choice == 'r')
        {
                printf("Enter coordinates of the cell to remove: ");
                scanf("%d %d", &x, &y);

                deletecell(x, y, board);
        }

	if(choice == 'n')
        {

		generation(board);
	
	}

	if(choice == 'q')
        {
                printf("Goodbye!");

	}

	if(choice == 'p')
        {
		while(1)
		{
			generation(board);
			display(board);
			usleep(1000000/20);
			system("clear");
		}	
	}
	
}
