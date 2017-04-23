//Timer
//Inicializa a contagem
void tStartTimer(stopWatch *timer) 
{
	QueryPerformanceCounter(&timer->start); 
}
//Para a contagem
void tStopTimer(stopWatch *timer) 
{
	QueryPerformanceCounter(&timer->stop); 
}
//Converte o tempo computado pelo stopWatch para segundos
double tLIToSecs(LARGE_INTEGER *L) 
{
	LARGE_INTEGER frequency;
	QueryPerformanceFrequency(&frequency);
	return ((double)L->QuadPart /(double)frequency.QuadPart);
}
//Retorna o numero de segundos passados na contagem
double tGetElapsedTime(stopWatch *timer) 
{
	LARGE_INTEGER time;
	time.QuadPart = (timer->stop).QuadPart - (timer->start).QuadPart;
	return tLIToSecs(&time) ;
}