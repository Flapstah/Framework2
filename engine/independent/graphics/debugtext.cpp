#include "common/stdafx.h"

#include "graphics/debugtext.h"

//==============================================================================

#define DEFINE_BYTE(_bit7_, _bit6_, _bit5_, _bit4_, _bit3_, _bit2_, _bit1_, _bit0_) ((_bit7_ << 7) | (_bit6_ << 6) | (_bit5_ << 5) | (_bit4_ << 4) | (_bit3_ << 3) | (_bit2_ << 2) | (_bit1_ << 1) | _bit0_)

//==============================================================================

namespace engine
{
	//============================================================================

	CDebugText::CDebugText(void)
	{
	}

	//============================================================================

	CDebugText::~CDebugText(void)
	{
	}

	//============================================================================

	void CDebugText::InitFontData(void)
	{
		// ' '
		m_font[' '-' '] = SChar(	DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															5 );

		// '!'
		m_font['!'-' '] = SChar(	DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															2 );

		// '"'
		m_font['\"'-' '] = SChar( DEFINE_BYTE(1,0,1,0,0,0,0,0),
															DEFINE_BYTE(1,0,1,0,0,0,0,0),
															DEFINE_BYTE(1,0,1,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															4 );

		// '#'
		m_font['#'-' '] = SChar(	DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,1,0,0,0,0),
															DEFINE_BYTE(1,1,1,1,1,0,0,0),
															DEFINE_BYTE(0,1,0,1,0,0,0,0),
															DEFINE_BYTE(1,1,1,1,1,0,0,0),
															DEFINE_BYTE(0,1,0,1,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );

		// '$'
		m_font['$'-' '] = SChar(	DEFINE_BYTE(0,0,1,0,0,0,0,0),
															DEFINE_BYTE(0,1,1,1,0,0,0,0),
															DEFINE_BYTE(1,0,1,0,0,0,0,0),
															DEFINE_BYTE(0,1,1,1,0,0,0,0),
															DEFINE_BYTE(0,0,1,0,1,0,0,0),
															DEFINE_BYTE(0,1,1,1,0,0,0,0),
															DEFINE_BYTE(0,0,1,0,0,0,0,0),
															6 );

		// '%'
		m_font['%'-' '] = SChar(	DEFINE_BYTE(0,1,0,0,0,0,1,0),
															DEFINE_BYTE(1,0,1,0,0,1,0,0),
															DEFINE_BYTE(1,0,1,0,1,0,0,0),
															DEFINE_BYTE(0,1,0,1,0,1,0,0),
															DEFINE_BYTE(0,0,1,0,1,0,1,0),
															DEFINE_BYTE(0,1,0,0,1,0,1,0),
															DEFINE_BYTE(1,0,0,0,0,1,0,0),
															7 );

		// '&'
		m_font['&'-' '] = SChar(	DEFINE_BYTE(0,0,1,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,1,0,0,0,0),
															DEFINE_BYTE(0,0,1,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,1,0,0,1,0),
															DEFINE_BYTE(1,0,0,0,1,1,0,0),
															DEFINE_BYTE(1,0,0,0,1,1,0,0),
															DEFINE_BYTE(0,1,1,1,0,0,1,0),
															7 );

		// '''
		m_font['\''-' '] = SChar(	DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															7 );

		// '('
		m_font['('-' '] = SChar(	DEFINE_BYTE(0,1,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,0,0,0,0,0),
															3 );

		// ')'
		m_font[')'-' '] = SChar(	DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															3 );

		// '*'
		m_font['*'-' '] = SChar(	DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,1,0,0,0,0,0),
															DEFINE_BYTE(1,0,1,0,1,0,0,0),
															DEFINE_BYTE(0,1,1,1,0,0,0,0),
															DEFINE_BYTE(0,1,0,1,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );

		// '+'
		m_font['+'-' '] = SChar(	DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,1,0,0,0,0,0),
															DEFINE_BYTE(0,0,1,0,0,0,0,0),
															DEFINE_BYTE(1,1,1,1,1,0,0,0),
															DEFINE_BYTE(0,0,1,0,0,0,0,0),
															DEFINE_BYTE(0,0,1,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );

		// ','
		m_font[','-' '] = SChar(	DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															3 );

		// '-'
		m_font['-'-' '] = SChar(	DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,1,1,1,1,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );

		// '.'
		m_font['.'-' '] = SChar(	DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															2 );

		// '/'
		m_font['/'-' '] = SChar(	DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,1,0,0,0),
															DEFINE_BYTE(0,0,0,1,0,0,0,0),
															DEFINE_BYTE(0,0,1,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );

		// '0'
		m_font['0'-' '] = SChar(	DEFINE_BYTE(0,1,1,1,0,0,0,0),
															DEFINE_BYTE(1,0,0,1,1,0,0,0),
															DEFINE_BYTE(1,0,1,0,1,0,0,0),
															DEFINE_BYTE(1,0,1,0,1,0,0,0),
															DEFINE_BYTE(1,1,0,0,1,0,0,0),
															DEFINE_BYTE(0,1,1,1,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );

		// '1'
		m_font['1'-' '] = SChar(	DEFINE_BYTE(0,0,1,0,0,0,0,0),
															DEFINE_BYTE(0,1,1,0,0,0,0,0),
															DEFINE_BYTE(0,0,1,0,0,0,0,0),
															DEFINE_BYTE(0,0,1,0,0,0,0,0),
															DEFINE_BYTE(0,0,1,0,0,0,0,0),
															DEFINE_BYTE(0,1,1,1,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );

		// '2'
		m_font['2'-' '] = SChar(	DEFINE_BYTE(0,1,1,1,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(0,0,0,0,1,0,0,0),
															DEFINE_BYTE(0,1,1,1,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,1,1,1,1,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );

		// '3'
		m_font['3'-' '] = SChar(	DEFINE_BYTE(0,1,1,1,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(0,0,1,1,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(0,1,1,1,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );

		// '4'
		m_font['4'-' '] = SChar(	DEFINE_BYTE(0,0,0,1,0,0,0,0),
															DEFINE_BYTE(0,0,1,1,0,0,0,0),
															DEFINE_BYTE(0,1,0,1,0,0,0,0),
															DEFINE_BYTE(1,0,0,1,0,0,0,0),
															DEFINE_BYTE(1,1,1,1,1,0,0,0),
															DEFINE_BYTE(0,0,0,1,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );

		// '5'
		m_font['5'-' '] = SChar(	DEFINE_BYTE(1,1,1,1,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,1,1,1,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(0,1,1,1,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );

		// '6'
		m_font['6'-' '] = SChar(	DEFINE_BYTE(0,1,1,1,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,1,1,1,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(0,1,1,1,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );

		// '7'
		m_font['7'-' '] = SChar(	DEFINE_BYTE(1,1,1,1,1,0,0,0),
															DEFINE_BYTE(0,0,0,0,1,0,0,0),
															DEFINE_BYTE(0,0,0,1,0,0,0,0),
															DEFINE_BYTE(0,0,1,0,0,0,0,0),
															DEFINE_BYTE(0,0,1,0,0,0,0,0),
															DEFINE_BYTE(0,0,1,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );

		// '8'
		m_font['8'-' '] = SChar(	DEFINE_BYTE(0,1,1,1,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,1,1,1,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(0,1,1,1,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );

		// '9'
		m_font['9'-' '] = SChar(	DEFINE_BYTE(0,1,1,1,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(0,1,1,1,1,0,0,0),
															DEFINE_BYTE(0,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,1,1,1,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );

		// ':'
		m_font[':'-' '] = SChar(	DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															2 );

		// ';'
		m_font[';'-' '] = SChar(	DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															3 );

		// '<'
		m_font['<'-' '] = SChar(	DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,1,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,1,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															4 );

		// '='
		m_font['='-' '] = SChar(	DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,1,1,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,1,1,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															4 );
		// '<'
		m_font['>'-' '] = SChar(	DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,1,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															4 );
		// '?'
		m_font['?'-' '] = SChar(	DEFINE_BYTE(0,1,1,1,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,1,0,0,0,0),
															DEFINE_BYTE(0,0,1,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,1,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );

		// '@'
		m_font['@'-' '] = SChar(	DEFINE_BYTE(0,1,1,1,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,1,1,0,0,0),
															DEFINE_BYTE(1,0,1,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,1,1,0,0,0),
															DEFINE_BYTE(0,1,1,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );

		// 'A'
		m_font['A'-' '] = SChar(	DEFINE_BYTE(0,0,1,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,1,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,1,1,1,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );

		// 'B'
		m_font['B'-' '] = SChar(	DEFINE_BYTE(1,1,1,1,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,1,1,1,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,1,1,1,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );

		// 'C'
		m_font['C'-' '] = SChar(	DEFINE_BYTE(0,1,1,1,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(0,1,1,1,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );

		// 'D'
		m_font['D'-' '] = SChar(	DEFINE_BYTE(1,1,1,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,1,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,1,0,0,0,0),
															DEFINE_BYTE(1,1,1,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );

		// 'E'
		m_font['E'-' '] = SChar(	DEFINE_BYTE(1,1,1,1,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,1,1,1,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,1,1,1,1,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );

		// 'F'
		m_font['F'-' '] = SChar(	DEFINE_BYTE(1,1,1,1,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,1,1,1,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );
		// 'G'
		m_font['G'-' '] = SChar(	DEFINE_BYTE(0,1,1,1,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,1,1,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(0,1,1,1,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );

		// 'H'
		m_font['H'-' '] = SChar(	DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,1,1,1,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );

		// 'I'
		m_font['I'-' '] = SChar(	DEFINE_BYTE(1,1,1,1,1,0,0,0),
															DEFINE_BYTE(0,0,1,0,0,0,0,0),
															DEFINE_BYTE(0,0,1,0,0,0,0,0),
															DEFINE_BYTE(0,0,1,0,0,0,0,0),
															DEFINE_BYTE(0,0,1,0,0,0,0,0),
															DEFINE_BYTE(1,1,1,1,1,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );

		// 'J'
		m_font['J'-' '] = SChar(	DEFINE_BYTE(1,1,1,1,1,0,0,0),
															DEFINE_BYTE(0,0,0,1,0,0,0,0),
															DEFINE_BYTE(0,0,0,1,0,0,0,0),
															DEFINE_BYTE(0,0,0,1,0,0,0,0),
															DEFINE_BYTE(1,0,0,1,0,0,0,0),
															DEFINE_BYTE(0,1,1,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );

		// 'K'
		m_font['K'-' '] = SChar(	DEFINE_BYTE(1,0,0,1,0,0,0,0),
															DEFINE_BYTE(1,0,1,0,0,0,0,0),
															DEFINE_BYTE(1,1,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,1,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,1,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );

		// 'L'
		m_font['L'-' '] = SChar(	DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,1,1,1,1,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );

		// 'M'
		m_font['M'-' '] = SChar(	DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,1,0,1,1,0,0,0),
															DEFINE_BYTE(1,0,1,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );

		// 'N'
		m_font['N'-' '] = SChar(	DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,1,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,1,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,1,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );

		// '0'
		m_font['O'-' '] = SChar(	DEFINE_BYTE(0,1,1,1,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(0,1,1,1,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );

		// 'P'
		m_font['P'-' '] = SChar(	DEFINE_BYTE(1,1,1,1,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,1,1,1,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );

		// 'Q'
		m_font['Q'-' '] = SChar(	DEFINE_BYTE(0,1,1,1,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,1,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,1,1,0,0,0),
															DEFINE_BYTE(0,1,1,1,1,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );

		// 'R'
		m_font['R'-' '] = SChar(	DEFINE_BYTE(1,1,1,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,1,0,0,0,0),
															DEFINE_BYTE(1,0,0,1,0,0,0,0),
															DEFINE_BYTE(1,1,1,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,1,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );
		// 'S'
		m_font['S'-' '] = SChar(	DEFINE_BYTE(0,1,1,1,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,1,1,1,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(0,1,1,1,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );

		// 'T'
		m_font['T'-' '] = SChar(	DEFINE_BYTE(1,1,1,1,1,0,0,0),
															DEFINE_BYTE(0,0,1,0,0,0,0,0),
															DEFINE_BYTE(0,0,1,0,0,0,0,0),
															DEFINE_BYTE(0,0,1,0,0,0,0,0),
															DEFINE_BYTE(0,0,1,0,0,0,0,0),
															DEFINE_BYTE(0,0,1,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );

		// 'U'
		m_font['U'-' '] = SChar(	DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(0,1,1,1,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );

		// 'V'
		m_font['V'-' '] = SChar(	DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(0,1,0,1,0,0,0,0),
															DEFINE_BYTE(0,1,0,1,0,0,0,0),
															DEFINE_BYTE(0,0,1,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );

		// 'W'
		m_font['W'-' '] = SChar(	DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,1,0,1,0,0,0),
															DEFINE_BYTE(1,1,0,1,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );

		// 'X'
		m_font['X'-' '] = SChar(	DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(0,1,0,1,0,0,0,0),
															DEFINE_BYTE(0,0,1,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,1,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );

		// 'Y'
		m_font['Y'-' '] = SChar(	DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(0,1,0,1,0,0,0,0),
															DEFINE_BYTE(0,0,1,0,0,0,0,0),
															DEFINE_BYTE(0,0,1,0,0,0,0,0),
															DEFINE_BYTE(0,0,1,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );

		// 'Z'
		m_font['Z'-' '] = SChar(	DEFINE_BYTE(1,1,1,1,1,0,0,0),
															DEFINE_BYTE(0,0,0,1,0,0,0,0),
															DEFINE_BYTE(0,0,1,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,1,1,1,1,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );

		// '['
		m_font['['-' '] = SChar(	DEFINE_BYTE(1,1,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,1,0,0,0,0,0,0),
															3 );

		// '\'
		m_font['\\'-' '] = SChar(	DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,1,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,1,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,1,0,0,0),
															DEFINE_BYTE(0,1,0,0,0,0,0,0),
															7 );

		// ']'
		m_font[']'-' '] = SChar(	DEFINE_BYTE(1,1,0,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,0,0,0,0,0),
															DEFINE_BYTE(1,1,0,0,0,0,0,0),
															3 );

		// '^'
		m_font['^'-' '] = SChar(	DEFINE_BYTE(0,0,1,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,1,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );

		// '_'
		m_font['_'-' '] = SChar(	DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,1,1,1,1,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );

		// '`'
		m_font['`'-' '] = SChar(	DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															3 );

		// 'a'
		m_font['a'-' '] = SChar(	DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,1,1,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,1,0,0,0,0),
															DEFINE_BYTE(0,1,1,1,0,0,0,0),
															DEFINE_BYTE(1,0,0,1,0,0,0,0),
															DEFINE_BYTE(0,1,1,0,1,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );

		// 'b'
		m_font['b'-' '] = SChar(	DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,1,1,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,1,0,0,0,0),
															DEFINE_BYTE(1,0,0,1,0,0,0,0),
															DEFINE_BYTE(1,1,1,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															5 );

		// 'c'
		m_font['c'-' '] = SChar(	DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,1,1,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,1,1,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															5 );

		// 'd'
		m_font['d'-' '] = SChar(	DEFINE_BYTE(0,0,0,1,0,0,0,0),
															DEFINE_BYTE(0,0,0,1,0,0,0,0),
															DEFINE_BYTE(0,1,1,1,0,0,0,0),
															DEFINE_BYTE(1,0,0,1,0,0,0,0),
															DEFINE_BYTE(1,0,0,1,0,0,0,0),
															DEFINE_BYTE(0,1,1,1,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															5 );

		// 'e'
		m_font['e'-' '] = SChar(	DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,1,1,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,1,0,0,0,0),
															DEFINE_BYTE(1,1,1,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,1,1,1,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															5 );

		// 'f'
		m_font['f'-' '] = SChar(	DEFINE_BYTE(0,1,1,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,1,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															4 );

		// 'g'
		m_font['g'-' '] = SChar(	DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,1,1,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,1,0,0,0,0),
															DEFINE_BYTE(0,1,1,1,0,0,0,0),
															DEFINE_BYTE(0,0,0,1,0,0,0,0),
															DEFINE_BYTE(1,1,1,0,0,0,0,0),
															5 );

		// 'h'
		m_font['h'-' '] = SChar(	DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,1,1,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,1,0,0,0,0),
															DEFINE_BYTE(1,0,0,1,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															5 );

		// 'i'
		m_font['i'-' '] = SChar(	DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,1,0,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,0,0,0,0,0),
															DEFINE_BYTE(1,1,1,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															4 );

		// 'j'
		m_font['j'-' '] = SChar(	DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,1,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,1,0,0,0,0,0),
															DEFINE_BYTE(1,0,1,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															4 );

		// 'k'
		m_font['k'-' '] = SChar(	DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,1,0,0,0,0,0),
															DEFINE_BYTE(1,1,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,1,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,1,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															5 );

		// 'l'
		m_font['l'-' '] = SChar(	DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															3 );

		// 'm'
		m_font['m'-' '] = SChar(	DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,1,0,1,0,0,0,0),
															DEFINE_BYTE(1,0,1,0,1,0,0,0),
															DEFINE_BYTE(1,0,1,0,1,0,0,0),
															DEFINE_BYTE(1,0,1,0,1,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );

		// 'n'
		m_font['n'-' '] = SChar(	DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,1,0,0,0,0,0),
															DEFINE_BYTE(1,1,0,1,0,0,0,0),
															DEFINE_BYTE(1,0,0,1,0,0,0,0),
															DEFINE_BYTE(1,0,0,1,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															5 );

		// 'o'
		m_font['o'-' '] = SChar(	DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,1,1,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,1,0,0,0,0),
															DEFINE_BYTE(1,0,0,1,0,0,0,0),
															DEFINE_BYTE(0,1,1,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															5 );

		// 'p'
		m_font['p'-' '] = SChar(	DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,1,1,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,1,0,0,0,0),
															DEFINE_BYTE(1,1,1,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															5 );

		// 'q'
		m_font['q'-' '] = SChar(	DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,1,1,1,0,0,0,0),
															DEFINE_BYTE(1,0,0,1,0,0,0,0),
															DEFINE_BYTE(0,1,1,1,0,0,0,0),
															DEFINE_BYTE(0,0,0,1,0,0,0,0),
															DEFINE_BYTE(0,0,0,1,0,0,0,0),
															5 );

		// 'r'
		m_font['r'-' '] = SChar(	DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,1,1,0,0,0,0),
															DEFINE_BYTE(1,1,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															5 );

		// 's'
		m_font['s'-' '] = SChar(	DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,1,1,1,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,1,1,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,1,0,0,0,0),
															DEFINE_BYTE(1,1,1,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															5 );

		// 't'
		m_font['t'-' '] = SChar(	DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,0,0,0,0,0),
															DEFINE_BYTE(1,1,1,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,1,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															4 );

		// 'u'
		m_font['u'-' '] = SChar(	DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,1,0,0,0,0),
															DEFINE_BYTE(1,0,0,1,0,0,0,0),
															DEFINE_BYTE(1,0,1,1,0,0,0,0),
															DEFINE_BYTE(0,1,0,1,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															5 );

		// 'v'
		m_font['v'-' '] = SChar(	DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(0,1,0,1,0,0,0,0),
															DEFINE_BYTE(0,0,1,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );

		// 'w'
		m_font['w'-' '] = SChar(	DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,1,0,1,0,0,0),
															DEFINE_BYTE(1,0,1,0,1,0,0,0),
															DEFINE_BYTE(1,0,1,0,1,0,0,0),
															DEFINE_BYTE(0,1,0,1,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );

		// 'x'
		m_font['x'-' '] = SChar(	DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(0,1,0,1,0,0,0,0),
															DEFINE_BYTE(0,0,1,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,1,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );

		// 'y'
		m_font['y'-' '] = SChar(	DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,1,0,0,0,0),
															DEFINE_BYTE(1,0,0,1,0,0,0,0),
															DEFINE_BYTE(0,1,1,1,0,0,0,0),
															DEFINE_BYTE(0,0,0,1,0,0,0,0),
															DEFINE_BYTE(1,1,1,0,0,0,0,0),
															5 );

		// 'z'
		m_font['z'-' '] = SChar(	DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,1,1,1,1,0,0,0),
															DEFINE_BYTE(0,0,0,1,0,0,0,0),
															DEFINE_BYTE(0,0,1,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,0,0,0,0,0),
															DEFINE_BYTE(1,1,1,1,1,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );

		// '{'
		m_font['{'-' '] = SChar(	DEFINE_BYTE(0,0,1,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,1,0,0,0,0,0),
															4 );

		// '|'
		m_font['|'-' '] = SChar(	DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															2 );

		// '}'
		m_font['}'-' '] = SChar(	DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,1,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															4 );

		// '~'
		m_font['~'-' '] = SChar(	DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,1,0,0,0,0),
															DEFINE_BYTE(1,0,1,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															5 );

		// undisplayable character
		m_font[94] =			SChar(	DEFINE_BYTE(1,1,1,1,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,1,0,1,1,0,0,0),
															DEFINE_BYTE(1,0,1,0,1,0,0,0),
															DEFINE_BYTE(1,1,0,1,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,1,1,1,1,0,0,0),
															6 );
	}

	//============================================================================
} // End [namespace engine]

//==============================================================================
// [EOF]

