#include <stdio.h>
//API
#include "EnsembleAPI.h"

int main(void)
{
	const std::string ensemble_ip = "192.168.212.11" ;
	const int ensemble_port = 5000 ;
	
	CEnsembleAPI cla_api ;

	cla_api.Ensemble_Network_Connect(ensemble_ip.c_str(), ensemble_port) ;

	if( cla_api.Ensemble_Network_IsOnline() )
	{
		printf("Success! Ensemble Network : %s:%d\n", ensemble_ip.c_str(), ensemble_port) ;
	}
	else
	{
		printf("Fail! Ensemble Network : %s:%d\n", ensemble_ip.c_str(), ensemble_port) ;
	}

	cla_api.Ensemble_Network_Disconnect() ;
	
	return 0 ;
}
