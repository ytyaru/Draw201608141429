#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")
#include "DirectX9DrawerScene1.h"
#include <tchar.h>

DirectX9DrawerScene1::DirectX9DrawerScene1(void)
{
	m_pFont = NULL;
}
DirectX9DrawerScene1::~DirectX9DrawerScene1(void)
{
}
void DirectX9DrawerScene1::Initialize()
{
	// LPDIRECT3DDEVICE9 ���K�v�B

	////�t�H���g�̐��� MS�S�V�b�N
	////�f�o�C�X,��������,������,�t�H���g�X�^�C��,�~�b�v�}�b�v�̃��x��,�Α̂ɂ��邩�ǂ���,�����Z�b�g,�o�͐��x,�o�͕i��,�t�H���g�s�b�`�ƃt�@�~��,�t�H���g��,�t�H���g�|�C���^
	//HRESULT hr = D3DXCreateFont(
	//	g_pd3dDevice, 
	//	40, 
	//	0, 
	//	FW_HEAVY, 
	//	1, 
	//	false, 
	//	SHIFTJIS_CHARSET, 
	//	OUT_TT_ONLY_PRECIS, 
	//	ANTIALIASED_QUALITY, 
	//	FF_DONTCARE, 
	//	_T("�l�r �S�V�b�N"), 
	//	&m_pFont);
	//if FAILED(hr){return(E_FAIL);}
}
void DirectX9DrawerScene1::Finalize()
{
	if (NULL != m_pFont) {
		m_pFont->Release();
		m_pFont = NULL;
	}
}
void DirectX9DrawerScene1::Draw(const LPDIRECT3DDEVICE9 lpD3DDev)
{
	lpD3DDev->Clear( 0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0,0,255), 1.0f, 0 );
	lpD3DDev->BeginScene();

	RECT rect;
	SetRect(&rect, 20, 20, 300, 300);//�`��ʒu

	if (NULL == m_pFont) {
		// https://msdn.microsoft.com/ja-jp/library/bb172773(v=vs.85).aspx
		HRESULT hr = D3DXCreateFont(
			lpD3DDev, 
			50,					// Height
			0,					// Width
			FW_HEAVY,			// Weight
			1,					// MipLevels
			false,				// Italic
			SHIFTJIS_CHARSET,	// 
			OUT_TT_ONLY_PRECIS, 
			ANTIALIASED_QUALITY, 
			FF_DONTCARE, 
			_T("�l�r �S�V�b�N"), 
			&m_pFont);
		//if FAILED(hr){return(E_FAIL);}
		if (FAILED(hr)) { throw "D3DXCreateFont�֐������s�����B(DirectX9DrawerScene1::Draw())"; }
	}
	else {
		// https://msdn.microsoft.com/ja-jp/library/bb173962(v=vs.85).aspx
		this->m_pFont->DrawText(
			NULL, 
			_T("DirectX9�ŕ`�撆�BDirectX9DrawerScene1"), 
			-1, 
			&rect, 
			DT_LEFT | DT_NOCLIP | DT_WORDBREAK , 
			D3DCOLOR_ARGB(255, 216, 216, 216));
	}

	lpD3DDev->EndScene();
	lpD3DDev->Present( NULL, NULL, NULL, NULL );
}