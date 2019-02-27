void LString_Concat(LString &t,LString &s,char c)
{
	p=t.head;
	while(p&&!(i=Find_Char(p,c)))
		p=p->next;
	if(!p)
	{
		t.tail->next=s.head;
		t.tail=s.tail;
	}
	else
	{
		q=p->next;
		r=(Chunk*)malloc(siozeof(chunk));
		for(j=0;j<i;j++)
			r->ch[j]='#';
		for(j=i;j<CHUNKSIZE;j++)
		{
			r->ch[j]=p->ch[j];
			p->ch[j]='#';
		}
		p->next=s.head;
		s.tail->next=r;
		r->next=q;
	}
	t.curlen+=s.curlen;
	s.curlen=0;
}
int Find_Char(Chunk*p,char c)
{
	for(i=0;i<CHUNKSIZE&&p->ch[i]!=c;i++)
	if(i==CHUNKSIZE) 
		return 0;
	else
		return i+1;
}
