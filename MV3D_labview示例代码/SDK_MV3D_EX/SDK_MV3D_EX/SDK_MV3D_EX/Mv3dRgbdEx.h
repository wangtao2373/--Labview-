#include "Mv3dRgbdApi.h"

#include <string.h>
#include <malloc.h>


#ifdef __cplusplus
extern "C" {
#endif
#ifdef  MV3D_RGBD_API_Ex
#else
#define MV3D_RGBD_API_Ex __declspec(dllexport)
#endif


typedef struct _MV3D_RGBD_GigEDEVICE_INFO_
{
	char                        chManufacturerName[32];             // �豸����
	char                        chModelName[32];                    // �豸�ͺ�
	char                        chDeviceVersion[32];                // �豸�汾
	char                        chManufacturerSpecificInfo[48];     // �豸����������Ϣ
	char                        chSerialNumber[16];                 // �豸���к�
	char                        chUserDefinedName[16];              // �豸�û��Զ�������
	int32_t          enDeviceType;                       // �豸���ͣ����ڡ�USB
	unsigned char               chMacAddress[8];                    // Mac��ַ
	int32_t           enIPCfgMode;                        // ��ǰIP����
	char                        chCurrentIp[16];                    // �豸��ǰIP
	char                        chCurrentSubNetMask[16];            // �豸��ǰ��������
	char                        chDefultGateWay[16];                // �豸Ĭ������
	char                        chNetExport[16];                    // ����IP��ַ
	uint8_t                     nReserved[16];                      // �����ֽ�
} MV3D_RGBD_GigEDEVICE_INFO;

typedef struct _MV3D_RGBD_U3DEVICE_INFO_
{
	char                        chManufacturerName[32];             // �豸����
	char                        chModelName[32];                    // �豸�ͺ�
	char                        chDeviceVersion[32];                // �豸�汾
	char                        chManufacturerSpecificInfo[48];     // �豸����������Ϣ
	char                        chSerialNumber[16];                 // �豸���к�
	char                        chUserDefinedName[16];              // �豸�û��Զ�������
	int32_t          enDeviceType;                       // �豸���ͣ����ڡ�USB
	uint32_t                    nVendorId;                          // ��Ӧ��ID�� 
	uint32_t                    nProductId;                         // ��ƷID�� 
	int32_t         enUsbProtocol;                      // ֧�ֵ�USBЭ��
	char                        chDeviceGUID[64];                   // �豸GUID��
	uint8_t                     nReserved[16];                      // �����ֽ� 
} MV3D_RGBD_U3DEVICE_INFO;



/************************************************************************
*  @fn     MV3D_RGBD_GetGigEDeviceList()
*  @brief  ��ȡGigE�豸�б�
*  @param  nDeviceType                 [IN]            �豸����,��Mv3dRgbdDeviceType,��ȫ����ȡ(DeviceType_Ethernet | DeviceType_USB)
*  @param  pstDeviceInfos              [IN OUT]        �豸�б�
*  @param  nMaxDeviceCount             [IN]            �豸�б���������
*  @param  pDeviceCount                [OUT]           ����б����豸����
*  @return �ɹ�������MV3D_RGBD_OK�����󣬷��ش�����

*  @fn     MV3D_RGBD_GetGigEDeviceList()
*  @brief  Gets GigE 3D cameras list
*  @param  nDeviceType                 [IN]            device type��refer to Mv3dRgbdDeviceType��get all(DeviceType_Ethernet | DeviceType_USB)
*  @param  pstDeviceInfos              [IN OUT]        devices list
*  @param  nMaxDeviceCount             [IN]            Max Number of device list caches
*  @param  pDeviceCount                [OUT]           number of devices in the fill list
*  @return Success, return MV3D_RGBD_OK. Failure, return error code
************************************************************************/
MV3D_RGBD_API_Ex MV3D_RGBD_STATUS MV3D_RGBD_GetGigEDeviceList(MV3D_RGBD_GigEDEVICE_INFO* pstGigEDeviceInfos, uint32_t nMaxDeviceCount, uint32_t* pDeviceCount);

/************************************************************************
*  @fn     MV3D_RGBD_GetU3DeviceList()
*  @brief  ��ȡUSB�豸�б�
*  @param  nDeviceType                 [IN]            �豸����,��Mv3dRgbdDeviceType,��ȫ����ȡ(DeviceType_Ethernet | DeviceType_USB)
*  @param  pstDeviceInfos              [IN OUT]        �豸�б�
*  @param  nMaxDeviceCount             [IN]            �豸�б���������
*  @param  pDeviceCount                [OUT]           ����б����豸����
*  @return �ɹ�������MV3D_RGBD_OK�����󣬷��ش�����

*  @fn     MV3D_RGBD_GetU3DeviceList()
*  @brief  Gets USB 3D cameras list
*  @param  nDeviceType                 [IN]            device type��refer to Mv3dRgbdDeviceType��get all(DeviceType_Ethernet | DeviceType_USB)
*  @param  pstDeviceInfos              [IN OUT]        devices list
*  @param  nMaxDeviceCount             [IN]            Max Number of device list caches
*  @param  pDeviceCount                [OUT]           number of devices in the fill list
*  @return Success, return MV3D_RGBD_OK. Failure, return error code
************************************************************************/
MV3D_RGBD_API_Ex MV3D_RGBD_STATUS MV3D_RGBD_GetU3DeviceList(MV3D_RGBD_U3DEVICE_INFO* pstU3DeviceInfos, uint32_t nMaxDeviceCount, uint32_t* pDeviceCount);

/************************************************************************
*  @fn     MV3D_RGBD_OpenGigEDevice()
*  @brief  ��GigE�豸
*  @param  handle                      [IN OUT]        ������
*  @param  pstDeviceInfo               [IN]            ö�ٵ��豸��Ϣ��Ĭ��Ϊ�գ��򿪵�һ�����
*  @return �ɹ�������MV3D_RGBD_OK�����󣬷��ش�����

*  @fn     MV3D_RGBD_OpenDevice()
*  @brief  open GigE device
*  @param  handle                      [IN OUT]        camera handle
*  @param  pstDeviceInfo               [IN]            enum camera info. the default is null, open first camera
*  @return Success, return MV3D_RGBD_OK. Failure, return error code
************************************************************************/
MV3D_RGBD_API_Ex MV3D_RGBD_STATUS MV3D_RGBD_OpenGigEDevice(HANDLE *handle, MV3D_RGBD_GigEDEVICE_INFO* pstGigeDeviceInfo = NULL);

/************************************************************************
*  @fn     MV3D_RGBD_OpenU3Device()
*  @brief  ��USB�豸
*  @param  handle                      [IN OUT]        ������
*  @param  pstDeviceInfo               [IN]            ö�ٵ��豸��Ϣ��Ĭ��Ϊ�գ��򿪵�һ�����
*  @return �ɹ�������MV3D_RGBD_OK�����󣬷��ش�����

*  @fn     MV3D_RGBD_OpenDevice()
*  @brief  open USB device
*  @param  handle                      [IN OUT]        camera handle
*  @param  pstDeviceInfo               [IN]            enum camera info. the default is null, open first camera
*  @return Success, return MV3D_RGBD_OK. Failure, return error code
************************************************************************/
MV3D_RGBD_API_Ex MV3D_RGBD_STATUS MV3D_RGBD_OpenU3Device(HANDLE *handle, MV3D_RGBD_U3DEVICE_INFO* pstU3DeviceInfo = NULL);

/************************************************************************
*  @fn     MV3D_RGBD_GetDeviceInfo
*  @brief  ��ȡ��ǰ�豸����ϸ��Ϣ
*  @param  handle                      [IN]            ������
*  @param  pstDevInfo                  [IN][OUT]       ���ظ��������й�����豸��Ϣ�ṹ��ָ��
*  @return �ɹ�,MV3D_RGBD_OK,ʧ��,���ش�����

*  @fn     MV3D_RGBD_GetDeviceInfo
*  @brief  Get current device information
*  @param  handle                      [IN]            camera handle
*  @param  pstDevInfo                  [IN][OUT]       Structure pointer of device information
*  @return Success, return MV3D_RGBD_OK. Failure, return error code
************************************************************************/
MV3D_RGBD_API_Ex MV3D_RGBD_STATUS MV3D_RGBD_GetU3DeviceInfo(HANDLE handle, MV3D_RGBD_U3DEVICE_INFO* pstDevInfo);

/************************************************************************
*  @fn     MV3D_RGBD_GetDeviceInfo
*  @brief  ��ȡ��ǰ�豸����ϸ��Ϣ
*  @param  handle                      [IN]            ������
*  @param  pstDevInfo                  [IN][OUT]       ���ظ��������й�����豸��Ϣ�ṹ��ָ��
*  @return �ɹ�,MV3D_RGBD_OK,ʧ��,���ش�����

*  @fn     MV3D_RGBD_GetDeviceInfo
*  @brief  Get current device information
*  @param  handle                      [IN]            camera handle
*  @param  pstDevInfo                  [IN][OUT]       Structure pointer of device information
*  @return Success, return MV3D_RGBD_OK. Failure, return error code
************************************************************************/
MV3D_RGBD_API_Ex MV3D_RGBD_STATUS MV3D_RGBD_GetGigEDeviceInfo(HANDLE handle, MV3D_RGBD_GigEDEVICE_INFO* pstDevInfo);


/************************************************************************
*  @fn     MV3D_RGBD_YUV422ToRGB
*  @brief  ��YUV422ת��ΪRGB
*  @param  pYuvImgge                  [IN][OUT]       �����YUV422����
*  @param  pRgbImage                  [IN][OUT]       �����RGB����
*  @return �ɹ�,MV3D_RGBD_OK,ʧ��,���ش����룬��֧�ֵĸ�ʽ

*  @fn     MV3D_RGBD_GetDeviceInfo
*  @brief  yuv422 image convert to rgb image
*  @param  pYuvImgge                  [IN][OUT]       In YUV422 data
*  @param  pRgbImage                  [IN][OUT]       Out RGB data
*  @return Success, return MV3D_RGBD_OK. Failure, return error code
************************************************************************/
MV3D_RGBD_API_Ex MV3D_RGBD_STATUS MV3D_RGBD_YUV422ToRGB(MV3D_RGBD_IMAGE_DATA *pYuvImgge, MV3D_RGBD_IMAGE_DATA* pRgbImage);















MV3D_RGBD_STATUS  MV3D_RGBD_GetU3DeviceInfo(HANDLE handle, MV3D_RGBD_U3DEVICE_INFO* pstU3DevInfo)
{
	MV3D_RGBD_DEVICE_INFO* pstDeviceInfo = new MV3D_RGBD_DEVICE_INFO();
	MV3D_RGBD_STATUS ret = MV3D_RGBD_GetDeviceInfo(handle, pstDeviceInfo);
	//��MV3D_RGBD_DEVICE_INFOת��ΪMV3D_RGBD_U3DEVICE_INFO

	strcpy_s(pstU3DevInfo->chDeviceVersion, pstDeviceInfo->chDeviceVersion);
	strcpy_s(pstU3DevInfo->chManufacturerName, pstDeviceInfo->chManufacturerName);
	strcpy_s(pstU3DevInfo->chManufacturerSpecificInfo, pstDeviceInfo->chManufacturerSpecificInfo);
	strcpy_s(pstU3DevInfo->chModelName, pstDeviceInfo->chModelName);
	strcpy_s(pstU3DevInfo->chSerialNumber, pstDeviceInfo->chSerialNumber);
	strcpy_s(pstU3DevInfo->chUserDefinedName, pstDeviceInfo->chUserDefinedName);
	pstU3DevInfo->enDeviceType = pstDeviceInfo->enDeviceType;
	strcpy_s(pstU3DevInfo->chDeviceGUID, pstDeviceInfo->SpecialInfo.stUsbInfo.chDeviceGUID);
	pstU3DevInfo->enUsbProtocol = pstDeviceInfo->SpecialInfo.stUsbInfo.enUsbProtocol;
	pstU3DevInfo->nProductId = pstDeviceInfo->SpecialInfo.stUsbInfo.nProductId;
	pstU3DevInfo->nVendorId = pstDeviceInfo->SpecialInfo.stUsbInfo.nVendorId;
	*pstU3DevInfo->nReserved = *pstDeviceInfo->SpecialInfo.stUsbInfo.nReserved;
	return ret;
}

MV3D_RGBD_STATUS  MV3D_RGBD_GetGigEDeviceInfo(HANDLE handle, MV3D_RGBD_GigEDEVICE_INFO* pstGigeDevInfo)
{
	MV3D_RGBD_DEVICE_INFO* pstDeviceInfo = new MV3D_RGBD_DEVICE_INFO();
	MV3D_RGBD_STATUS ret = MV3D_RGBD_GetDeviceInfo(handle, pstDeviceInfo);
	//	��MV3D_RGBD_DEVICE_INFOת��ΪMV3D_RGBD_GigEDEVICE_INFO

	strcpy_s(pstGigeDevInfo->chDeviceVersion, pstDeviceInfo->chDeviceVersion);
	strcpy_s(pstGigeDevInfo->chManufacturerName, pstDeviceInfo->chManufacturerName);
	strcpy_s(pstGigeDevInfo->chManufacturerSpecificInfo, pstDeviceInfo->chManufacturerSpecificInfo);
	strcpy_s(pstGigeDevInfo->chModelName, pstDeviceInfo->chModelName);
	strcpy_s(pstGigeDevInfo->chSerialNumber, pstDeviceInfo->chSerialNumber);
	strcpy_s(pstGigeDevInfo->chUserDefinedName, pstDeviceInfo->chUserDefinedName);
	pstGigeDevInfo->enDeviceType = pstDeviceInfo->enDeviceType;

	strcpy_s(pstGigeDevInfo->chCurrentIp, pstDeviceInfo->SpecialInfo.stNetInfo.chCurrentIp);
	strcpy_s(pstGigeDevInfo->chCurrentSubNetMask, pstDeviceInfo->SpecialInfo.stNetInfo.chCurrentSubNetMask);
	strcpy_s(pstGigeDevInfo->chDefultGateWay, pstDeviceInfo->SpecialInfo.stNetInfo.chDefultGateWay);
	*pstGigeDevInfo->chMacAddress = *pstDeviceInfo->SpecialInfo.stNetInfo.chMacAddress;
	strcpy_s(pstGigeDevInfo->chNetExport, pstDeviceInfo->SpecialInfo.stNetInfo.chNetExport);
	pstGigeDevInfo->enIPCfgMode = pstDeviceInfo->SpecialInfo.stNetInfo.enIPCfgMode;
	*pstGigeDevInfo->nReserved = *pstDeviceInfo->SpecialInfo.stNetInfo.nReserved;
	return ret;
}

MV3D_RGBD_STATUS MV3D_RGBD_GetGigEDeviceList(MV3D_RGBD_GigEDEVICE_INFO* pstGigEDeviceInfos, uint32_t nMaxDeviceCount, uint32_t* pDeviceCount)
{
	MV3D_RGBD_DEVICE_INFO* pstDeviceInfos = (MV3D_RGBD_DEVICE_INFO*)pstGigEDeviceInfos;
	MV3D_RGBD_STATUS ret = MV3D_RGBD_GetDeviceList(DeviceType_Ethernet, pstDeviceInfos, nMaxDeviceCount, pDeviceCount);
	//��MV3D_RGBD_DEVICE_INFOת��ΪMV3D_RGBD_GigEDEVICE_INFO
	pstGigEDeviceInfos = (MV3D_RGBD_GigEDEVICE_INFO*)pstDeviceInfos;
	return ret;
}

MV3D_RGBD_STATUS  MV3D_RGBD_GetU3DeviceList(MV3D_RGBD_U3DEVICE_INFO* pstU3DeviceInfos, uint32_t nMaxDeviceCount, uint32_t* pDeviceCount)
{
	MV3D_RGBD_DEVICE_INFO* pstDeviceInfos = (MV3D_RGBD_DEVICE_INFO*)pstU3DeviceInfos;
	MV3D_RGBD_STATUS ret = MV3D_RGBD_GetDeviceList(DeviceType_USB, pstDeviceInfos, nMaxDeviceCount, pDeviceCount);
	//��MV3D_RGBD_DEVICE_INFOת��ΪMV3D_RGBD_GigEDEVICE_INFO
	pstU3DeviceInfos = (MV3D_RGBD_U3DEVICE_INFO*)pstDeviceInfos;
	return ret;
}

MV3D_RGBD_STATUS MV3D_RGBD_OpenGigEDevice(HANDLE *handle, MV3D_RGBD_GigEDEVICE_INFO* pstGigeDeviceInfo) {
	MV3D_RGBD_DEVICE_INFO* pstDeviceInfo = new MV3D_RGBD_DEVICE_INFO();

	//��MV3D_RGBD_GigEDEVICE_INFOת��ΪMV3D_RGBD_DEVICE_INFO������MV3D_RGBD_OpenDevice����

	strcpy_s(pstDeviceInfo->chDeviceVersion, pstGigeDeviceInfo->chDeviceVersion);
	strcpy_s(pstDeviceInfo->chManufacturerName, pstGigeDeviceInfo->chManufacturerName);
	strcpy_s(pstDeviceInfo->chManufacturerSpecificInfo, pstGigeDeviceInfo->chManufacturerSpecificInfo);
	strcpy_s(pstDeviceInfo->chModelName, pstGigeDeviceInfo->chModelName);
	strcpy_s(pstDeviceInfo->chSerialNumber, pstGigeDeviceInfo->chSerialNumber);
	strcpy_s(pstDeviceInfo->chUserDefinedName, pstGigeDeviceInfo->chUserDefinedName);
	pstDeviceInfo->enDeviceType = (Mv3dRgbdDeviceType)pstGigeDeviceInfo->enDeviceType;
	strcpy_s(pstDeviceInfo->SpecialInfo.stNetInfo.chCurrentIp, pstGigeDeviceInfo->chCurrentIp);
	strcpy_s(pstDeviceInfo->SpecialInfo.stNetInfo.chCurrentSubNetMask, pstGigeDeviceInfo->chCurrentSubNetMask);
	strcpy_s(pstDeviceInfo->SpecialInfo.stNetInfo.chDefultGateWay, pstGigeDeviceInfo->chDefultGateWay);
	*pstDeviceInfo->SpecialInfo.stNetInfo.chMacAddress = *pstGigeDeviceInfo->chMacAddress;
	strcpy_s(pstDeviceInfo->SpecialInfo.stNetInfo.chNetExport, pstGigeDeviceInfo->chNetExport);
	pstDeviceInfo->SpecialInfo.stNetInfo.enIPCfgMode = (Mv3dRgbdIpCfgMode)pstGigeDeviceInfo->enIPCfgMode;
	*pstDeviceInfo->SpecialInfo.stNetInfo.nReserved = *pstGigeDeviceInfo->nReserved;
	MV3D_RGBD_STATUS ret = MV3D_RGBD_OpenDevice(handle, pstDeviceInfo);
	return ret;
}

MV3D_RGBD_STATUS MV3D_RGBD_OpenU3Device(HANDLE *handle, MV3D_RGBD_U3DEVICE_INFO* pstU3DeviceInfo) {
	MV3D_RGBD_DEVICE_INFO* pstDeviceInfo = new MV3D_RGBD_DEVICE_INFO();
	//��MV3D_RGBD_U3DEVICE_INFOת��ΪMV3D_RGBD_DEVICE_INFO������MV3D_RGBD_OpenDevice����
	strcpy_s(pstDeviceInfo->chDeviceVersion, pstU3DeviceInfo->chDeviceVersion);
	strcpy_s(pstDeviceInfo->chManufacturerName, pstU3DeviceInfo->chManufacturerName);
	strcpy_s(pstDeviceInfo->chManufacturerSpecificInfo, pstU3DeviceInfo->chManufacturerSpecificInfo);
	strcpy_s(pstDeviceInfo->chModelName, pstU3DeviceInfo->chModelName);
	strcpy_s(pstDeviceInfo->chSerialNumber, pstU3DeviceInfo->chSerialNumber);
	strcpy_s(pstDeviceInfo->chUserDefinedName, pstU3DeviceInfo->chUserDefinedName);
	pstDeviceInfo->enDeviceType = (Mv3dRgbdDeviceType)pstU3DeviceInfo->enDeviceType;
	*pstDeviceInfo->SpecialInfo.stUsbInfo.chDeviceGUID = *pstU3DeviceInfo->chDeviceGUID;
	pstDeviceInfo->SpecialInfo.stUsbInfo.enUsbProtocol = (Mv3dRgbdUsbProtocol)pstU3DeviceInfo->enUsbProtocol;
	pstDeviceInfo->SpecialInfo.stUsbInfo.nProductId = pstU3DeviceInfo->nProductId;
	*pstDeviceInfo->SpecialInfo.stUsbInfo.nReserved = *pstU3DeviceInfo->nReserved;
	pstDeviceInfo->SpecialInfo.stUsbInfo.nVendorId = pstU3DeviceInfo->nVendorId;

	MV3D_RGBD_STATUS ret = MV3D_RGBD_OpenDevice(handle, pstDeviceInfo);
	return ret;
}



MV3D_RGBD_STATUS MV3D_RGBD_YUV422ToRGB(MV3D_RGBD_IMAGE_DATA *pYuvImgge, MV3D_RGBD_IMAGE_DATA* pRgbImage) {
	//2.������ʽ�����ټ�������δ����     R��G��B~[0, 255]   U��V~[0, 255]
	//R = Y + ((360 * (V - 128)) >> 8);
	//G = Y - (((88 * (U - 128) + 184 * (V - 128))) >> 8);
	//B = Y + ((455 * (U - 128)) >> 8);
	pRgbImage->enImageType = Mv3dRgbdImageType::ImageType_RGB8_Planar;
	pRgbImage->nDataLen = pYuvImgge->nHeight*pYuvImgge->nWidth * 3;
	pRgbImage->nFrameNum = pYuvImgge->nFrameNum;
	pRgbImage->nHeight = pYuvImgge->nHeight;
	pRgbImage->nTimeStamp = pYuvImgge->nTimeStamp;
	pRgbImage->nWidth = pYuvImgge->nWidth;
	static uint8_t buffer[1280 * 720 * 9];
	for (size_t i = 0; i < pRgbImage->nWidth*pRgbImage->nHeight; i += 2)
	{
		uint16_t Y1 = (uint16_t)pYuvImgge->pData[i * 2];
		uint16_t U1 = (uint16_t)(pYuvImgge->pData[i * 2 + 1]);
		uint16_t Y2 = (uint16_t)pYuvImgge->pData[i * 2 + 2];
		uint16_t V2 = (uint16_t)(pYuvImgge->pData[i * 2 + 3]);

		buffer[i * 3 + 0] = (uint8_t)(Y1 + ((360 * (V2 - 128)) >> 8));								//Rͨ��
		buffer[i * 3 + 1] = (uint8_t)(Y1 - (((88 * (U1 - 128) + 184 * (V2 - 128))) >> 8));			//Gͨ��
		buffer[i * 3 + 2] = (uint8_t)(Y1 + ((455 * (U1 - 128)) >> 8));								//Bͨ��
		buffer[i * 3 + 3] = (uint8_t)(Y2 + ((360 * (V2 - 128)) >> 8));								//Rͨ��
		buffer[i * 3 + 4] = (uint8_t)(Y2 - (((88 * (U1 - 128) + 184 * (V2 - 128))) >> 8));			//Gͨ��
		buffer[i * 3 + 5] = (uint8_t)(Y2 + ((455 * (U1 - 128)) >> 8));								//Bͨ��
	}
	pRgbImage->pData = buffer;
	return 0;
}












#ifdef __cplusplus
}
#endif
