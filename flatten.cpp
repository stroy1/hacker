


head
|
node1 -> node2 -> node3	-> end4 -> node5 -> node6 -> node11 -> node12 -> node13 -> NULL
												|
												node7 -> node8 -> NULL;
												|
												node9 -> node10 -> NULL


Node * flatten(Node * self){

	if(self->down != NULL){
		Node * end = flatten(self->down);
		Node * oldNext = self->next;
		self->next = self->down;
		self->down = NULL;
		end -> next = oldNext;
	}


	if(self->next != NULL){
		Node * end = flatten(self->next);
		return end;
	}

	return self;
}