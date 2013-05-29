#include "VirusScanCallback.hpp"

#pragma once

class ConsoleCallback : public VirusScanCallback
{
public:
		virtual void onScanStarted();
		virtual void onVirusFound();
		virtual void onScanFinished();
};