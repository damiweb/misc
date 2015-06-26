/* type equation  */

	do{
		cin >> ws; /* ignore whitespaces */
		if (isdigit(cin.peek())){
			int n = 0;
			cin >> n;
			cout << "wpisano liczbę:" << endl << n << endl;
		}
		else {
			char c = '0';
			cin >> c;
			cout << "wpisano znak:" << endl << c << endl;
		}
	}while(cin.get() != '\n');