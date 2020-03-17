#include <stdio.h>
//API
#include "EnsembleAPI.h"
#include "CImageBuf2Mat.h"

int main(void)
{
	const std::string ensemble_ip = "192.168.212.11" ;
	const int ensemble_port = 5000 ;
	
	CEnsembleAPI cla_api ;

	cla_api.Ensemble_Network_Connect(ensemble_ip.c_str(), ensemble_port) ;

	if( cla_api.Ensemble_Network_IsOnline() )
	{
		printf("Success! Ensemble Network : %s:%d\n", ensemble_ip.c_str(), ensemble_port) ;

		while(1)
		{
			CImageBuf2Mat cls_imagebuf2mat ;
			
			ImageBuf image ;
			
			//Get Source Image
			cla_api.Ensemble_Camera_Capture_SW_Trigger() ;		//New Image
            //cla_api.Ensemble_Source_Get_Image(IMAGE_ADD_TIME+IMAGE_ADD_SOURCE_INFO, &image) ;
            cla_api.Ensemble_Source_Get_Image(0, &image) ;

			cv::Mat mat_image ;
			if( image.p_buf != NULL )
            {
				mat_image = cls_imagebuf2mat.Cvt(image) ;

				delete [] image.p_buf ;
				image.p_buf = NULL ;
            }

			if( !mat_image.empty() )
			{
				//show
				cv::imshow("image", mat_image) ;
			}

			char c = cv::waitKey(1) ;
			if( c == 'q' || c == 'Q' ) break ;
		};
	}
	else
	{
		printf("Fail! Ensemble Network : %s:%d\n", ensemble_ip.c_str(), ensemble_port) ;
	}

	cla_api.Ensemble_Network_Disconnect() ;
	
	return 0 ;
}
