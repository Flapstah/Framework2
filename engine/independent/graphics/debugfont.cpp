#include "common/stdafx.h"

#include "graphics/debugfont.h"

//==============================================================================

#define DEFINE_BYTE(_bit7_, _bit6_, _bit5_, _bit4_, _bit3_, _bit2_, _bit1_, _bit0_) ((_bit7_ << 7) | (_bit6_ << 6) | (_bit5_ << 5) | (_bit4_ << 4) | (_bit3_ << 3) | (_bit2_ << 2) | (_bit1_ << 1) | _bit0_)

//==============================================================================

namespace engine
{
	//============================================================================

	CDebugFont::CDebugFont(void)
	{
		InitFontData();
	}

	//============================================================================

	CDebugFont::~CDebugFont(void)
	{
	}

	//============================================================================

	void CDebugFont::InitFontData(void)
	{
		// ' '
		m_font[' '-' '] = SGlyph(	DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															5 );

		// '!'
		m_font['!'-' '] = SGlyph(	DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															2 );

		// '"'
		m_font['\"'-' '] = SGlyph( DEFINE_BYTE(1,0,1,0,0,0,0,0),
															DEFINE_BYTE(1,0,1,0,0,0,0,0),
															DEFINE_BYTE(1,0,1,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															4 );

		// '#'
		m_font['#'-' '] = SGlyph(	DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,0,1,0,0,0),
															DEFINE_BYTE(1,1,1,1,1,1,0,0),
															DEFINE_BYTE(0,1,0,0,1,0,0,0),
															DEFINE_BYTE(0,1,0,0,1,0,0,0),
															DEFINE_BYTE(1,1,1,1,1,1,0,0),
															DEFINE_BYTE(0,1,0,0,1,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															7 );

		// '$'
		m_font['$'-' '] = SGlyph(	DEFINE_BYTE(0,0,1,0,1,0,0,0),
															DEFINE_BYTE(0,1,1,1,1,1,1,0),
															DEFINE_BYTE(1,0,1,0,1,0,0,0),
															DEFINE_BYTE(0,1,1,1,1,1,0,0),
															DEFINE_BYTE(0,0,1,0,1,0,1,0),
															DEFINE_BYTE(1,1,1,1,1,1,0,0),
															DEFINE_BYTE(0,0,1,0,1,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															7 );

		// '%'
		m_font['%'-' '] = SGlyph(	DEFINE_BYTE(0,1,0,0,0,0,1,0),
															DEFINE_BYTE(1,0,1,0,0,1,0,0),
															DEFINE_BYTE(1,0,1,0,1,0,0,0),
															DEFINE_BYTE(0,1,0,1,0,1,0,0),
															DEFINE_BYTE(0,0,1,0,1,0,1,0),
															DEFINE_BYTE(0,1,0,0,1,0,1,0),
															DEFINE_BYTE(1,0,0,0,0,1,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															7 );

		// '&'
		m_font['&'-' '] = SGlyph(	DEFINE_BYTE(0,0,1,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,1,0,0,0,0),
															DEFINE_BYTE(0,0,1,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,1,0,0,1,0),
															DEFINE_BYTE(1,0,0,0,1,1,0,0),
															DEFINE_BYTE(1,0,0,0,1,1,0,0),
															DEFINE_BYTE(0,1,1,1,0,0,1,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															7 );

		// '''
		m_font['\''-' '] = SGlyph(	DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															7 );

		// '('
		m_font['('-' '] = SGlyph(	DEFINE_BYTE(0,1,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															3 );

		// ')'
		m_font[')'-' '] = SGlyph(	DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															3 );

		// '*'
		m_font['*'-' '] = SGlyph(	DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,1,0,0,0,0,0),
															DEFINE_BYTE(1,0,1,0,1,0,0,0),
															DEFINE_BYTE(0,1,1,1,0,0,0,0),
															DEFINE_BYTE(0,1,0,1,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );

		// '+'
		m_font['+'-' '] = SGlyph(	DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,1,0,0,0,0,0),
															DEFINE_BYTE(0,0,1,0,0,0,0,0),
															DEFINE_BYTE(1,1,1,1,1,0,0,0),
															DEFINE_BYTE(0,0,1,0,0,0,0,0),
															DEFINE_BYTE(0,0,1,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );

		// ','
		m_font[','-' '] = SGlyph(	DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															3 );

		// '-'
		m_font['-'-' '] = SGlyph(	DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,1,1,1,1,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );

		// '.'
		m_font['.'-' '] = SGlyph(	DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															2 );

		// '/'
		m_font['/'-' '] = SGlyph(	DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,1,0,0,0),
															DEFINE_BYTE(0,0,0,1,0,0,0,0),
															DEFINE_BYTE(0,0,1,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );

		// '0'
		m_font['0'-' '] = SGlyph(	DEFINE_BYTE(0,1,1,1,0,0,0,0),
															DEFINE_BYTE(1,0,0,1,1,0,0,0),
															DEFINE_BYTE(1,0,1,0,1,0,0,0),
															DEFINE_BYTE(1,0,1,0,1,0,0,0),
															DEFINE_BYTE(1,0,1,0,1,0,0,0),
															DEFINE_BYTE(1,1,0,0,1,0,0,0),
															DEFINE_BYTE(0,1,1,1,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );

		// '1'
		m_font['1'-' '] = SGlyph(	DEFINE_BYTE(0,0,1,0,0,0,0,0),
															DEFINE_BYTE(0,1,1,0,0,0,0,0),
															DEFINE_BYTE(0,0,1,0,0,0,0,0),
															DEFINE_BYTE(0,0,1,0,0,0,0,0),
															DEFINE_BYTE(0,0,1,0,0,0,0,0),
															DEFINE_BYTE(0,0,1,0,0,0,0,0),
															DEFINE_BYTE(0,1,1,1,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );

		// '2'
		m_font['2'-' '] = SGlyph(	DEFINE_BYTE(0,1,1,1,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(0,0,0,0,1,0,0,0),
															DEFINE_BYTE(0,1,1,1,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,1,1,1,1,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );

		// '3'
		m_font['3'-' '] = SGlyph(	DEFINE_BYTE(0,1,1,1,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(0,0,0,0,1,0,0,0),
															DEFINE_BYTE(0,0,1,1,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(0,1,1,1,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );

		// '4'
		m_font['4'-' '] = SGlyph(	DEFINE_BYTE(0,0,0,1,0,0,0,0),
															DEFINE_BYTE(0,0,1,1,0,0,0,0),
															DEFINE_BYTE(0,1,0,1,0,0,0,0),
															DEFINE_BYTE(0,1,0,1,0,0,0,0),
															DEFINE_BYTE(1,0,0,1,0,0,0,0),
															DEFINE_BYTE(1,1,1,1,1,0,0,0),
															DEFINE_BYTE(0,0,0,1,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );

		// '5'
		m_font['5'-' '] = SGlyph(	DEFINE_BYTE(1,1,1,1,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,1,1,1,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(0,1,1,1,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );

		// '6'
		m_font['6'-' '] = SGlyph(	DEFINE_BYTE(0,1,1,1,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,1,1,1,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(0,1,1,1,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );

		// '7'
		m_font['7'-' '] = SGlyph(	DEFINE_BYTE(1,1,1,1,1,0,0,0),
															DEFINE_BYTE(0,0,0,0,1,0,0,0),
															DEFINE_BYTE(0,0,0,1,0,0,0,0),
															DEFINE_BYTE(0,0,1,0,0,0,0,0),
															DEFINE_BYTE(0,0,1,0,0,0,0,0),
															DEFINE_BYTE(0,0,1,0,0,0,0,0),
															DEFINE_BYTE(0,0,1,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );

		// '8'
		m_font['8'-' '] = SGlyph(	DEFINE_BYTE(0,1,1,1,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(0,1,1,1,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(0,1,1,1,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );

		// '9'
		m_font['9'-' '] = SGlyph(	DEFINE_BYTE(0,1,1,1,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(0,1,1,1,1,0,0,0),
															DEFINE_BYTE(0,0,0,0,1,0,0,0),
															DEFINE_BYTE(0,0,0,0,1,0,0,0),
															DEFINE_BYTE(0,1,1,1,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );

		// ':'
		m_font[':'-' '] = SGlyph(	DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															2 );

		// ';'
		m_font[';'-' '] = SGlyph(	DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															3 );

		// '<'
		m_font['<'-' '] = SGlyph(	DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,1,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,1,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															4 );

		// '='
		m_font['='-' '] = SGlyph(	DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,1,1,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,1,1,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															4 );
		// '<'
		m_font['>'-' '] = SGlyph(	DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,1,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															4 );
		// '?'
		m_font['?'-' '] = SGlyph(	DEFINE_BYTE(0,1,1,1,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,1,0,0,0,0),
															DEFINE_BYTE(0,0,1,0,0,0,0,0),
															DEFINE_BYTE(0,0,1,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,1,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );

		// '@'
		m_font['@'-' '] = SGlyph(	DEFINE_BYTE(0,1,1,1,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,1,1,0,0,0),
															DEFINE_BYTE(1,0,1,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,1,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,1,1,1,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );

		// 'A'
		m_font['A'-' '] = SGlyph(	DEFINE_BYTE(0,1,1,1,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,1,1,1,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );

		// 'B'
		m_font['B'-' '] = SGlyph(	DEFINE_BYTE(1,1,1,1,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,1,1,1,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,1,1,1,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );

		// 'C'
		m_font['C'-' '] = SGlyph(	DEFINE_BYTE(0,1,1,1,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(0,1,1,1,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );

		// 'D'
		m_font['D'-' '] = SGlyph(	DEFINE_BYTE(1,1,1,1,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,1,1,1,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );

		// 'E'
		m_font['E'-' '] = SGlyph(	DEFINE_BYTE(1,1,1,1,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,1,1,1,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,1,1,1,1,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );

		// 'F'
		m_font['F'-' '] = SGlyph(	DEFINE_BYTE(1,1,1,1,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,1,1,1,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );
		// 'G'
		m_font['G'-' '] = SGlyph(	DEFINE_BYTE(0,1,1,1,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,1,1,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(0,1,1,1,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );

		// 'H'
		m_font['H'-' '] = SGlyph(	DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,1,1,1,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );

		// 'I'
		m_font['I'-' '] = SGlyph(	DEFINE_BYTE(1,1,1,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,0,0,0,0,0),
															DEFINE_BYTE(1,1,1,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															4 );

		// 'J'
		m_font['J'-' '] = SGlyph(	DEFINE_BYTE(0,0,0,0,1,0,0,0),
															DEFINE_BYTE(0,0,0,0,1,0,0,0),
															DEFINE_BYTE(0,0,0,0,1,0,0,0),
															DEFINE_BYTE(0,0,0,0,1,0,0,0),
															DEFINE_BYTE(0,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(0,1,1,1,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );

		// 'K'
		m_font['K'-' '] = SGlyph(	DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,1,0,0,0,0),
															DEFINE_BYTE(1,0,1,0,0,0,0,0),
															DEFINE_BYTE(1,1,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,1,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,1,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );

		// 'L'
		m_font['L'-' '] = SGlyph(	DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,1,1,1,1,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );

		// 'M'
		m_font['M'-' '] = SGlyph(	DEFINE_BYTE(1,0,0,0,0,0,1,0),
															DEFINE_BYTE(1,1,0,0,0,1,1,0),
															DEFINE_BYTE(1,0,1,0,1,0,1,0),
															DEFINE_BYTE(1,0,0,1,0,0,1,0),
															DEFINE_BYTE(1,0,0,0,0,0,1,0),
															DEFINE_BYTE(1,0,0,0,0,0,1,0),
															DEFINE_BYTE(1,0,0,0,0,0,1,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															8 );

		// 'N'
		m_font['N'-' '] = SGlyph(	DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,1,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,1,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,1,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );

		// '0'
		m_font['O'-' '] = SGlyph(	DEFINE_BYTE(0,1,1,1,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(0,1,1,1,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );

		// 'P'
		m_font['P'-' '] = SGlyph(	DEFINE_BYTE(1,1,1,1,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,1,1,1,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );

		// 'Q'
		m_font['Q'-' '] = SGlyph(	DEFINE_BYTE(0,1,1,1,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,1,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,1,1,0,0,0),
															DEFINE_BYTE(0,1,1,1,1,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,1,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															7 );

		// 'R'
		m_font['R'-' '] = SGlyph(	DEFINE_BYTE(1,1,1,1,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,1,1,1,0,0,0,0),
															DEFINE_BYTE(1,0,0,1,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );
		// 'S'
		m_font['S'-' '] = SGlyph(	DEFINE_BYTE(0,1,1,1,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,1,1,1,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(0,1,1,1,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );

		// 'T'
		m_font['T'-' '] = SGlyph(	DEFINE_BYTE(1,1,1,1,1,0,0,0),
															DEFINE_BYTE(0,0,1,0,0,0,0,0),
															DEFINE_BYTE(0,0,1,0,0,0,0,0),
															DEFINE_BYTE(0,0,1,0,0,0,0,0),
															DEFINE_BYTE(0,0,1,0,0,0,0,0),
															DEFINE_BYTE(0,0,1,0,0,0,0,0),
															DEFINE_BYTE(0,0,1,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );

		// 'U'
		m_font['U'-' '] = SGlyph(	DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(0,1,1,1,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );

		// 'V'
		m_font['V'-' '] = SGlyph(	DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(0,1,0,1,0,0,0,0),
															DEFINE_BYTE(0,1,0,1,0,0,0,0),
															DEFINE_BYTE(0,0,1,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );

		// 'W'
		m_font['W'-' '] = SGlyph(	DEFINE_BYTE(1,0,0,0,0,0,1,0),
															DEFINE_BYTE(1,0,0,0,0,0,1,0),
															DEFINE_BYTE(1,0,0,1,0,0,1,0),
															DEFINE_BYTE(1,0,0,1,0,0,1,0),
															DEFINE_BYTE(0,1,0,1,0,1,0,0),
															DEFINE_BYTE(0,1,0,1,0,1,0,0),
															DEFINE_BYTE(0,0,1,0,1,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															8 );

		// 'X'
		m_font['X'-' '] = SGlyph(	DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(0,1,0,1,0,0,0,0),
															DEFINE_BYTE(0,0,1,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,1,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );

		// 'Y'
		m_font['Y'-' '] = SGlyph(	DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(0,1,0,1,0,0,0,0),
															DEFINE_BYTE(0,0,1,0,0,0,0,0),
															DEFINE_BYTE(0,0,1,0,0,0,0,0),
															DEFINE_BYTE(0,0,1,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );

		// 'Z'
		m_font['Z'-' '] = SGlyph(	DEFINE_BYTE(1,1,1,1,1,0,0,0),
															DEFINE_BYTE(0,0,0,0,1,0,0,0),
															DEFINE_BYTE(0,0,0,1,0,0,0,0),
															DEFINE_BYTE(0,0,1,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,1,1,1,1,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );

		// '['
		m_font['['-' '] = SGlyph(	DEFINE_BYTE(1,1,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,1,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															3 );

		// '\'
		m_font['\\'-' '] = SGlyph(	DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,1,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,1,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,1,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );

		// ']'
		m_font[']'-' '] = SGlyph(	DEFINE_BYTE(1,1,0,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,0,0,0,0,0),
															DEFINE_BYTE(1,1,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															3 );

		// '^'
		m_font['^'-' '] = SGlyph(	DEFINE_BYTE(0,0,1,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,1,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );

		// '_'
		m_font['_'-' '] = SGlyph(	DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,1,1,1,1,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );

		// '`'
		m_font['`'-' '] = SGlyph(	DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															3 );

		// 'a'
		m_font['a'-' '] = SGlyph(	DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,1,1,1,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,1,0,0,0),
															DEFINE_BYTE(0,1,1,1,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(0,1,1,1,1,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );

		// 'b'
		m_font['b'-' '] = SGlyph(	DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,1,1,1,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,1,1,1,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );

		// 'c'
		m_font['c'-' '] = SGlyph(	DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,1,1,1,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(0,1,1,1,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );

		// 'd'
		m_font['d'-' '] = SGlyph(	DEFINE_BYTE(0,0,0,0,1,0,0,0),
															DEFINE_BYTE(0,0,0,0,1,0,0,0),
															DEFINE_BYTE(0,1,1,1,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(0,1,1,1,1,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );

		// 'e'
		m_font['e'-' '] = SGlyph(	DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,1,1,1,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,1,1,1,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,1,1,1,1,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );

		// 'f'
		m_font['f'-' '] = SGlyph(	DEFINE_BYTE(0,0,1,1,1,0,0,0),
															DEFINE_BYTE(0,1,0,0,0,0,0,0),
															DEFINE_BYTE(1,1,1,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );

		// 'g'
		m_font['g'-' '] = SGlyph(	DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,1,1,1,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(0,1,1,1,1,0,0,0),
															DEFINE_BYTE(0,0,0,0,1,0,0,0),
															DEFINE_BYTE(0,1,1,1,0,0,0,0),
															6 );

		// 'h'
		m_font['h'-' '] = SGlyph(	DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,1,1,1,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );

		// 'i'
		m_font['i'-' '] = SGlyph(	DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															2 );

		// 'j'
		m_font['j'-' '] = SGlyph(	DEFINE_BYTE(0,1,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															3 );

		// 'k'
		m_font['k'-' '] = SGlyph(	DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,1,0,0,0,0),
															DEFINE_BYTE(1,0,1,0,0,0,0,0),
															DEFINE_BYTE(1,1,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,1,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,1,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															5 );

		// 'l'
		m_font['l'-' '] = SGlyph(	DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															3 );

		// 'm'
		m_font['m'-' '] = SGlyph(	DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,1,1,0,1,1,0,0),
															DEFINE_BYTE(1,0,0,1,0,0,1,0),
															DEFINE_BYTE(1,0,0,1,0,0,1,0),
															DEFINE_BYTE(1,0,0,1,0,0,1,0),
															DEFINE_BYTE(1,0,0,1,0,0,1,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															8 );

		// 'n'
		m_font['n'-' '] = SGlyph(	DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,1,1,0,0,0,0),
															DEFINE_BYTE(1,1,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );

		// 'o'
		m_font['o'-' '] = SGlyph(	DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,1,1,1,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(0,1,1,1,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );

		// 'p'
		m_font['p'-' '] = SGlyph(	DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,1,1,1,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,1,1,1,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															6 );

		// 'q'
		m_font['q'-' '] = SGlyph(	DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,1,1,1,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(0,1,1,1,1,0,0,0),
															DEFINE_BYTE(0,0,0,0,1,0,0,0),
															DEFINE_BYTE(0,0,0,0,1,0,0,0),
															6 );

		// 'r'
		m_font['r'-' '] = SGlyph(	DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,1,1,0,0,0,0),
															DEFINE_BYTE(1,1,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															5 );

		// 's'
		m_font['s'-' '] = SGlyph(	DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,1,1,1,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,1,1,1,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,1,1,1,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															5 );

		// 't'
		m_font['t'-' '] = SGlyph(	DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,0,0,0,0,0),
															DEFINE_BYTE(1,1,1,1,0,0,0,0),
															DEFINE_BYTE(0,1,0,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,1,1,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															5 );

		// 'u'
		m_font['u'-' '] = SGlyph(	DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,1,1,0,0,0),
															DEFINE_BYTE(0,1,1,0,1,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );

		// 'v'
		m_font['v'-' '] = SGlyph(	DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(0,1,0,1,0,0,0,0),
															DEFINE_BYTE(0,0,1,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );

		// 'w'
		m_font['w'-' '] = SGlyph(	DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,1,0,0,1,0),
															DEFINE_BYTE(1,0,0,1,0,0,1,0),
															DEFINE_BYTE(1,0,0,1,0,0,1,0),
															DEFINE_BYTE(1,0,0,1,0,0,1,0),
															DEFINE_BYTE(0,1,1,0,1,1,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															8 );

		// 'x'
		m_font['x'-' '] = SGlyph(	DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(0,1,0,1,0,0,0,0),
															DEFINE_BYTE(0,0,1,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,1,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );

		// 'y'
		m_font['y'-' '] = SGlyph(	DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(0,1,1,1,1,0,0,0),
															DEFINE_BYTE(0,0,0,0,1,0,0,0),
															DEFINE_BYTE(0,1,1,1,0,0,0,0),
															6 );

		// 'z'
		m_font['z'-' '] = SGlyph(	DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,1,1,1,1,0,0,0),
															DEFINE_BYTE(0,0,0,1,0,0,0,0),
															DEFINE_BYTE(0,0,1,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,0,0,0,0,0),
															DEFINE_BYTE(1,1,1,1,1,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );

		// '{'
		m_font['{'-' '] = SGlyph(	DEFINE_BYTE(0,0,1,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,1,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															4 );

		// '|'
		m_font['|'-' '] = SGlyph(	DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															2 );

		// '}'
		m_font['}'-' '] = SGlyph(	DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,1,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,0,0,0,0,0),
															DEFINE_BYTE(1,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															4 );

		// '~'
		m_font['~'-' '] = SGlyph(	DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,1,0,1,0,0,0,0),
															DEFINE_BYTE(1,0,1,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															5 );

		// undisplayable character
		m_font[94] =			SGlyph(	DEFINE_BYTE(1,1,1,1,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,1,0,1,1,0,0,0),
															DEFINE_BYTE(1,0,1,0,1,0,0,0),
															DEFINE_BYTE(1,1,0,1,1,0,0,0),
															DEFINE_BYTE(1,0,0,0,1,0,0,0),
															DEFINE_BYTE(1,1,1,1,1,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															DEFINE_BYTE(0,0,0,0,0,0,0,0),
															6 );
	}

	//============================================================================

	const CDebugFont::SGlyph* CDebugFont::GetGlyph(char glyph) const
	{
		const SGlyph* pGlyph = &m_font[94];

		if ((glyph >= ' ') || (glyph <= '~'))
		{
			glyph -= ' ';
			pGlyph = &m_font[static_cast<uint8>(glyph)];
		}

		return pGlyph;
	}

	//============================================================================

	uint8 CDebugFont::GetFontHeight(void) const
	{
		return 9;
	}

	//============================================================================
} // End [namespace engine]

//==============================================================================
// [EOF]

