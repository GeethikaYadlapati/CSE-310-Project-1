void merge(tree *, int, int, int);
void merge_sort(tree *, int, int);
symbol* makeTree(int argc, char* argv[]);

symbol* makeTree(int argc, char* argv[]){
    initialize();
ifstream inputFile;
inputFile.open(argv[1]);
    string line;
    while(getline(inputFile, line)){
        char *line2 = &line[0];
        int i = 0;
        string strindex;
        int index = -1;
        string freq;
     while(line2[i]!= '\0' && line2[i] != '\n'){
    	 if ( index == -1 && line2[i] != '\t' )
    	 {
    		 strindex = strindex + line2[i];
    	 }
    	 else if ( index != -1 && line2[i] != '\t' )
    	 {
    		 freq = freq +  line2[i];
    	 }
         if(line2[i] == '\t'){
        	 index = std::stoi(strindex);
         }
         i++;
     }
     if ( index != -1 )
     {
    	 Symbols[index].freq = std::stoi(freq);
     }
    }


    tree *Alpha =  (tree*) malloc(sizeof(tree)*52);
    int AlphaLength = 52;
    tree *NonAlpha =  (tree*) malloc(sizeof(tree)*76);
    //tree NonAlpha[76];
    int NonAlphaLength = 76;
    int ind = 0;
    for(int x = 65; x < 123; x++){
        	if ( (x >=65 && x <91) || (x>=97 && x <123) )
        	{
				Alpha[ind].symbol = x;
					for(int p = 0; p < NSYMBOLS; p++){
						if(Symbols[p].symbol == Alpha[ind].symbol){
							Alpha[ind].freq = Symbols[p].freq;
							Alpha[ind].root = &Symbols[p];
						}
					}
					ind++;
        	}
    }

    ind = 0;
    for(int i = 0; i < NSYMBOLS; i++){
    	if ( (i >=0 && i <65) || (i >= 91 && i < 97) || (i >= 123 && i < NSYMBOLS) )
    	{
            	//cout << i << "-" << j << "-" << int(k) + "\n";
                NonAlpha[ind].symbol = i;
                for(int q = 0; q <  NSYMBOLS; q++){
                    if(Symbols[q].symbol == NonAlpha[ind].symbol){
                        NonAlpha[ind].freq = Symbols[q].freq;
                        NonAlpha[ind].root = &Symbols[q];
                    }
                }
                ind++;
        }
    }
    if(strcasecmp(argv[2],"insertion") == 0){
        int q, key;
        for(int p = 1; p < 52; p++){
        	tree temp = Alpha[p];
            key = Alpha[p].freq;
            q = p - 1;
            while(q >= 0 && Alpha[q].freq > key){
                Alpha[q + 1] = Alpha[q];
                q = q - 1;
            }
            Alpha[q + 1] = temp;
        }

        int j, key2;
        for(int i = 1; i < 76; i++){
        	tree temp = NonAlpha[i];
            key2 = NonAlpha[i].freq;
            j = i - 1;
            while(j >= 0 && NonAlpha[j].freq > key2){
                NonAlpha[j + 1] = NonAlpha[j];
                j = j - 1;
            }
            NonAlpha[j + 1] = temp;
        }
    }else if(strcasecmp(argv[2],"merge") == 0){
        merge_sort(Alpha, 0, 51);
        merge_sort(NonAlpha, 0, 75);

    }else{
        cout << "invalid second argument. Type insertion or merge.";
    }
    while ( AlphaLength >= 2 ){
    	if ( Alpha[0].freq == 0 && Alpha[1].freq == 0 )
    	{
    	    for(int j = 2; j < AlphaLength; j++){
    	        Alpha[j-2] = Alpha[j];
    	    }
    		AlphaLength = AlphaLength - 2;
    		continue;
    	}
    struct symbol *t = (symbol*) malloc(sizeof(symbol));
    t->parent = NULL;
    t->left = Alpha[0].root;
    t->right = Alpha[1].root;
    t->freq = Alpha[0].freq + Alpha[1].freq;
    tree temp0 = Alpha[0];
    if ( Alpha[0].root != NULL )
    {
    	Alpha[0].root->parent = t;
    }
    if ( Alpha[1].root != NULL )
    {
    	Alpha[1].root->parent = t;
    }

    for(int j = 2; j < AlphaLength; j++){
        Alpha[j-2] = Alpha[j];
    }
    AlphaLength = AlphaLength - 1;
    bool isCreated = false;
    for(int i = 0; i  < AlphaLength-1; i++){
        if(t->freq < Alpha[i].freq){
            for(int p = AlphaLength-2; p > i - 1; p--){
                Alpha[p+1] = Alpha[p];
            }
            Alpha[i] = temp0;
            Alpha[i].freq = t->freq;
            Alpha[i].root = t;
            isCreated = true;
            break;
        }
    }
    if ( !isCreated )
    {
    	Alpha[AlphaLength-1] = temp0;
        Alpha[AlphaLength-1].freq = t->freq;
        //if ( AlphaLength != 1 )
        {
        	Alpha[AlphaLength-1].root = t;
        }
    }

    }
    while( NonAlphaLength >= 2 ){
    	if ( NonAlpha[0].freq == 0 && NonAlpha[1].freq == 0 )
    	{
    	    for(int j = 2; j < NonAlphaLength; j++){
    	    	NonAlpha[j-2] = NonAlpha[j];
    	    }
    	    NonAlphaLength = NonAlphaLength - 2;
    		continue;
    	}
    struct symbol *t = (symbol*) malloc(sizeof(symbol));
    t->parent = NULL;
    t->left = NonAlpha[0].root;
    t->right = NonAlpha[1].root;
    t->freq = NonAlpha[0].freq + NonAlpha[1].freq;
    tree temp0 = NonAlpha[0];
    if ( NonAlpha[0].root != NULL )
    {
    	NonAlpha[0].root->parent = t;
    }
    if ( NonAlpha[1].root != NULL )
    {
    	NonAlpha[1].root->parent = t;
    }

    for(int j = 2; j < NonAlphaLength; j++){
    	NonAlpha[j-2] = NonAlpha[j];
    }
    NonAlphaLength = NonAlphaLength - 1;
    bool isCreated = false;
    for(int i = 0; i  < NonAlphaLength-1; i++){
        if(t->freq < NonAlpha[i].freq){
            for(int p = NonAlphaLength-2; p > i - 1; p--){
                NonAlpha[p+1] = NonAlpha[p];
            }
            NonAlpha[i] = temp0;
            NonAlpha[i].freq = t->freq;
            NonAlpha[i].root = t;
            isCreated = true;
            break;
        }
    }
    if ( !isCreated )
    {
    	NonAlpha[NonAlphaLength-1] = temp0;
    	NonAlpha[NonAlphaLength-1].freq = t->freq;
        //if ( NonAlphaLength != 1 )
        {
        	NonAlpha[NonAlphaLength-1].root = t;
        }
    }

    }
    //repeat the steps or try defining a method and calling it twice for  both the arrays

struct symbol *Root = (symbol*) malloc(sizeof(symbol));

Root->left = Alpha[0].root;
Root->freq = Alpha[0].freq+NonAlpha[0].freq;
Alpha[0].root->parent = Root;
Root->right = NonAlpha[0].root;
NonAlpha[0].root->parent = Root;

return Root;
}

void merge_sort(tree *arr, int low, int high)
{
    int mid;
    if (low < high){
        //divide the array at mid and sort independently using merge sort
        mid=(low+high)/2;
        merge_sort(arr,low,mid);
        merge_sort(arr,mid+1,high);
        //merge or conquer sorted arrays
        merge(arr,low,high,mid);
    }
}
// Merge sort
void merge(tree *arr, int low, int high, int mid)
{
    int i, j, k;
    tree c[76];
    i = low;
    k = low;
    j = mid + 1;
    while (i <= mid && j <= high) {
        if (arr[i].freq < arr[j].freq) {
            c[k] = arr[i];
            k++;
            i++;
        }
        else  {
            c[k] = arr[j];
            k++;
            j++;
        }
    }
    while (i <= mid) {
        c[k] = arr[i];
        k++;
        i++;
    }
    while (j <= high) {
        c[k] = arr[j];
        k++;
        j++;
    }
    for (i = low; i < k; i++)  {
        arr[i] = c[i];
    }
}