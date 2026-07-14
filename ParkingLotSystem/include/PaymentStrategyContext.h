#pragma once

#include <memory>
#include <string>

#include "PaymentStrategy.h"
#include "FlatPayment.h"
#include "VehicleBasedPayment.h"

class PaymentStrategyContext{
public:
    void setPaymentStrategy(std::string& strategy){
        if(strategy == "FLAT"){
            _strategy = std::make_unique<FlatPayment>();
        }else if(strategy == "VEHICLEBASED"){
            _strategy = std::make_unique<VehicleBasedPayment>();
        }
    }

private:
    std::unique_ptr<PaymentStrategy> _strategy;

};