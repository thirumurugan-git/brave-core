/* Copyright (c) 2021 The Brave Authors. All rights reserved.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef BRAVE_VENDOR_BAT_NATIVE_LEDGER_SRC_BAT_LEDGER_INTERNAL_WALLET_WALLET_H_
#define BRAVE_VENDOR_BAT_NATIVE_LEDGER_SRC_BAT_LEDGER_INTERNAL_WALLET_WALLET_H_

#include <stdint.h>

#include <memory>
#include <string>

#include "base/containers/flat_map.h"
#include "bat/ledger/internal/endpoint/promotion/promotion_server.h"
#include "bat/ledger/internal/wallet/wallet_balance.h"
#include "bat/ledger/internal/wallet/wallet_create.h"
#include "bat/ledger/internal/wallet/wallet_recover.h"
#include "bat/ledger/ledger.h"
#include "third_party/abseil-cpp/absl/types/optional.h"

namespace ledger {
class LedgerImpl;

namespace wallet {

class Wallet {
 public:
  explicit Wallet(LedgerImpl* ledger);
  ~Wallet();

  void CreateWalletIfNecessary(absl::optional<std::string>&& geo_country,
                               CreateRewardsWalletCallback callback);

  void RecoverWallet(const std::string& pass_phrase,
                     ledger::LegacyResultCallback callback);

  std::string GetWalletPassphrase(mojom::RewardsWalletPtr wallet);

  void FetchBalance(ledger::FetchBalanceCallback callback);

  void ExternalWalletAuthorization(
      const std::string& wallet_type,
      const base::flat_map<std::string, std::string>& args,
      ledger::ExternalWalletAuthorizationCallback callback);

  void DisconnectWallet(const std::string& wallet_type,
                        ledger::LegacyResultCallback callback);

  void DisconnectAllWallets(ledger::LegacyResultCallback callback);

  mojom::RewardsWalletPtr GetWallet();
  mojom::RewardsWalletPtr GetWallet(bool* corrupted);

  bool SetWallet(mojom::RewardsWalletPtr wallet);

  void LinkRewardsWallet(const std::string& destination_payment_id,
                         ledger::PostSuggestionsClaimCallback callback);

 private:
  void OnClaimWallet(ledger::PostSuggestionsClaimCallback callback,
                     mojom::Result result);

  LedgerImpl* ledger_;  // NOT OWNED
  std::unique_ptr<WalletCreate> create_;
  std::unique_ptr<WalletRecover> recover_;
  std::unique_ptr<WalletBalance> balance_;
  std::unique_ptr<endpoint::PromotionServer> promotion_server_;
};

}  // namespace wallet
}  // namespace ledger

#endif  // BRAVE_VENDOR_BAT_NATIVE_LEDGER_SRC_BAT_LEDGER_INTERNAL_WALLET_WALLET_H_
