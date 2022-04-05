from pykrx import stock

df = stock.get_market_ohlcv_by_date(fromdate="20220405", todate="20220405", ticker="005930")
print(df)
