/*
    Registration Number:202000506
    Name:Ishita Sinha
    Algorithm for "Sparse to compact conversion."
    Algorithm for "Compact to sparse conversion."
*/
int sparseToCompact(int sparse[10][10], int compact[15][3], int row, int col)
{
    int i=0,j=0,k=1, nonZeroCount=0;

    compact[0][0]=row;
    compact[0][1]=col;
    
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            if(sparse[i][j]!=0)
            {
                nonZeroCount++;
                compact[k][0]=i;
                compact[k][1]=j;
                compact[k][2]=sparse[i][j];
                k++;
            }
        }
    }
    compact[0][2]=nonZeroCount;

    return nonZeroCount;
}
void compactToSparse(int sparse[10][10], int compact[15][3], int nz)
{
    int row=0,col=0, i=0,j=0;
    
    row=compact[0][0];
    col=compact[0][1];
    nz=compact[0][2];
    for(i=0;i<row;i++)
    {	 	  	   	    	      	   	        	 	
        for(j=0;j<col;j++)
        {
            sparse[i][j]=0;
        }
    }
    for(i=1;i<=nz;i++)
    {
        sparse[compact[i][0]][compact[i][1]]=compact[i][2];
    }
}