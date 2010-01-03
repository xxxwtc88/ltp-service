#include "LTML.h"
namespace HIT_IR_LTP{
	LTML::LTML()
		:xml()
	{
	}

	bool LTML::SetEncoding(const string& encodeType){
		xml.SetEncoding(encodeType);
		return true;
	}

	std::string LTML::GetXMLStr() const
	{
		std::string xmlStr;
		xml.SaveDOM(xmlStr);
		return xmlStr;
	}

	bool LTML::IsAnalyzed()
	{
		return false;
	}

	bool LTML::HasSent() const
	{
		return xml.QueryNote(LTPData.NOTE_SENT);
	}

	bool LTML::HasWS() const
	{
		return xml.QueryNote(LTPData.NOTE_WORD);
	}

	bool LTML::HasPOS() const
	{
		return xml.QueryNote(LTPData.NOTE_POS);

	}

	bool LTML::HasNE() const
	{
		return xml.QueryNote(LTPData.NOTE_NE);

	}

	bool LTML::HasParser() const
	{
		return xml.QueryNote(LTPData.NOTE_PARSER);
	}

	bool LTML::HasWSD() const
	{
		return xml.QueryNote(LTPData.NOTE_WSD);
	}

	bool LTML::HasSRL() const
	{
		return xml.QueryNote(LTPData.NOTE_SRL);
	}

	void LTML::SetOver()
	{
		xml.SetOver();
	}

	LTML::~LTML()
	{
		xml.ClearDOM();
	}
}
