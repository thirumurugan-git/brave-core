import styled from 'styled-components'
import { AssetIconProps, AssetIconFactory, WalletButton } from '../../shared/style'

interface StyleProps {
  disabled: boolean
  isPanel: boolean
}

export const StyledWrapper = styled(WalletButton) <Partial<StyleProps>>`
  display: flex;
  align-items: center;
  justify-content: space-between;
  flex-direction: row;
  width: 100%;
  margin: 8px 0px;
  cursor: ${(p) => p.disabled ? 'default' : 'pointer'};
  outline: none;
  background: none;
  border: none;
`

export const NameAndIcon = styled.div`
  display: flex;
  align-items: center;
  justify-content: center;
  flex-direction: row;
`

export const AssetName = styled.span<Partial<StyleProps>>`
  font-family: Poppins;
  font-size: 13px;
  line-height: 20px;
  letter-spacing: 0.01em;
  color: ${(p) => p.isPanel ? p.theme.palette.white : p.theme.color.text01};
`

export const BalanceColumn = styled.div`
  display: flex;
  align-items: flex-end;
  justify-content: center;
  flex-direction: column;
`

export const FiatBalanceText = styled.span<Partial<StyleProps>>`
  font-family: Poppins;
  font-size: 13px;
  line-height: 20px;
  letter-spacing: 0.01em;
  color: ${(p) => p.isPanel ? p.theme.palette.white : p.theme.color.text01};
`

export const AssetBalanceText = styled.span<Partial<StyleProps>>`
  font-family: Poppins;
  font-size: 12px;
  line-height: 18px;
  letter-spacing: 0.01em;
  color: ${(p) => p.isPanel ? p.theme.palette.white : p.theme.color.text03};
`

// Construct styled-component using JS object instead of string, for editor
// support with custom AssetIconFactory.
//
// Ref: https://styled-components.com/docs/advanced#style-objects
export const AssetIcon = AssetIconFactory<AssetIconProps>({
  width: '40px',
  height: 'auto'
})
