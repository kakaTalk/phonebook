// define the treenode
typedef struct treeNode{
	NodeData data;
    struct treeNode *left, *right;
}TreeNode,*TreeNodePtr;

// define the BinaryTree 
typedef struct{
	TreeNodePtr root;
    int type;  //experimental - var should hold how tree is sorted(i.e. by fname, lname or number)
}BinaryTree;


//create node containing contact info
NodeData makeNodeData(char * fname, char * lname, char * phoneNumber){
    NodeData temp;

    strcpy(temp.fname, fname);
    strcpy(temp.lname, lname);
    strcpy(temp.phoneNumber, phoneNumber);

    return temp;
}

//create tree node for binary tree containing contact info 
TreeNodePtr makeTreeNode(NodeData d){
    TreeNodePtr node = (TreeNodePtr) malloc(sizeof(TreeNode));
    node->data = d;
    return node;
}

//add data to binary tree; no duplicates allowed
TreeNodePtr add(char *fname, char *lname, char *phoneNumber, TreeNodePtr root){

    if (root == NULL) return makeTreeNode(makeNodeData(fname, lname, phoneNumber));
    else if (strcmp(lname, root->data.lname) < 0) add(fname, lname, phoneNumber, root->left);
    else if (strcmp(lname, root->data.lname) > 0) add(fname, lname, phoneNumber, root->right);
    else {
        printf("Information already exists in phone book");
        return root;
    }
}

//retreive contact info from last name
TreeNodePtr retrieve(char *lname, TreeNodePtr root){
    if (root == NULL || strcmp(root->data.lname, lname) == 0) return root; //NULL or node is validated in Phonebook.c
    else if (strcmp(root->data.lname, lname) < 0) retrieve(lname, root->left);
    else  retrieve(lname, root->right);

}
/*
Algorithm delete(R, str)
	Input Binary tree root R and a string str
	Output Binary tree root with node containing str deleted
	if root = NULL then
		return NULL
	endif
	if str < num member of pointer R then
		delete(left member of pointer R, str)
	elseif str > num member of pointer R then
		delete(right member of pointer R, str)
	else
		if left member of pointer R = NULL AND right member of pointer R = NULL then  
			free(root)
			return NULL
		elseif left member of pointer R = NULL then   
			temp <-- pointer R
			R <-- right member of pointer 
			free(temp)
		elseif right member of pointer R = NULL then 
			temp <-- pointer R
			R <-- left member of pointer 
			free(temp)
		else
			max <-- NULL
			temp <--- left member of pointer R
			while  right member of temp != NULL
				temp <--- right member of temp
			endwhile
			max <-- temp
			name member of R <-- name member of max
			phone number member of max <-- phone number of max
			delete(left member of R, string member of max)
		endif
	endif
return R
*/

/*Algorithm write(txt, R)
	Input A text file txt to write to and binary tree root R
	Output Text file containing binary tree contents
	
	fp <--- open txt file for writing
	if fp = NULL then
		PRINT file does not exist
		EXIT
	
	PostOrderTraversalWrite(fp, R)
	close(fp)
	return;
	
Algorithm PostOrderTraversalWrite(fp, R)
	Input A text file stream fp and binary tree R
	Output Text file containing binary tree contents
	if R = NULL
		return;
			
	PostOrderTraversalWrite(fp, left member of R)
	PostOrderTraversalWrite(fp, right member of R)
	fprintf(fp, "%s %s %s", fname member of R, lname member of R, num member of here)
*/

/*

Algorithm load(txt, R)
	Input txt file address to load data from and binary tree root R
	Output Binary Tree R with data loaded from File fp
	
	fp <--- open txt file to read
	if fp = NULL then
		PRINT file does not exist
	EXIT
	
	tmpfname <-- a char array
	tmplname <--- a char array
	tmpnum <--- a char array
	
	buffer <--- a char array
	
	while not EOF 
		node <--- allocate memory for node
		node->fname <--- tmpfname
		node->lname <--- tmplname
		node->num <--- tmpphonenumber
		node->left <--- NULL
		node->right <--- NULL
		R <--- add(root member of R, node)
		
	return R
*/

/*
Algorithm sort(R, val)
	Input  Binary tree root R and integer val indicating type of attribute to sort
	Output Sorted Binary tree R and display its contents
	
	newR <-- a new empty Binary Tree root
	if (type of attribute member of R != val)
		getSortedTree(R, newR)
	InOrderTraversal(newR)
	return newR
	
Algorithm InOrderTraversal(R)
	Input Binary Tree R
	Output Displaying contents of Binary Tree R
		if R = NULL
			return;
			
		InOrderTraversal(fp, left member of R)
		InOrderTraversal(fp, right member of R)
		printf("%s %s %s", fname member of R, lname member of R, num member of here)	
*/

