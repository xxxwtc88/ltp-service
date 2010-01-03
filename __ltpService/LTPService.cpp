#include "LTPService.h"

namespace HIT_IR_LTP{
	LTPService::~LTPService(void)
	{
	}

	void LTPService::Analyze(LTML& ltml_out, const std::string& option, const std::string& analyzeString)
	{
		ls.SetAnalysisOptions(option);
		ls.SetXmlOption(false);
		std::string resultStr;
		ls.Analyze(analyzeString, resultStr);
		ltml_out.ClearDOM();
		ltml_out.SetEncoding(ls.GetEncoding());
		ltml_out.LoadLtml(resultStr);
		ltml_out.SetOver();
	}

	void LTPService::Analyze(LTML& ltml_out, const std::string& option, const LTML& ltml_in)
	{
		ls.SetAnalysisOptions(option);
		ls.SetXmlOption(true);
		std::string resultStr;
		ls.Analyze(ltml_in.GetXMLStr(), resultStr);
		ltml_out.ClearDOM();
		ltml_out.SetEncoding(ls.GetEncoding());
		ltml_out.LoadLtml(resultStr);
		ltml_out.SetOver();
	}
}
