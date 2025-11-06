# Optimal Strategies of HighFrequency Traders *

 Jiangmin Xu

First Draft:November 15.2013 This Draft: November 14, 2015

### ABSTRACT

This paper develops a model of the optimal strategies of high-frequency traders (HFTs) to rationalize their pinging activities.Pinging is defined as limit orders submitted inside the bid-ask spread that are cancelled shortly.The HFT in my model uses pinging to control his inventory or chase the short-term price momentum without learning or manipulative motives.I show that the model can match over $70\%$ of the pinging activities observed in the data,and demonstrate how the HFT's pinging behaviors vary across stocks.The result confirms that pinging is rationalizable as part of the dynamic trading strategies of HFTs.

------------------------------------------------------------------

## 1Introduction

A recent and ongoing heated debate concerns high-frequency traders and high-frequency trading activities (HFT stands for high-frequency trader/trading thereafter). The interest in this subject has grown significantly after the Flash Crash, because HFTs appear as a black-box mystery to the general public as well as to the academic world.1 One type of HFT activity that has attracted a great deal of attention due to HFTs' speed advantage is the so-called pinging activity. Pinging, or the most aggressive feeting order activity, is defined as the submission of limit orders inside the bid-ask spread that are cancelled very shortly.2 These activities occur in the scale of seconds or milliseconds with extremely low latency which is “the hallmark of proprietary trading by HFTs" (Hasbrouck and Saar (2013)).3

Regulators have expressed concerns over such pinging activities, the main one being that pinging done by HFTs might be manipulative. As pointed out in a concept release of the Securities and Exchange Commission (SEC), HFTs could use pinging orders to detect and learn about hidden orders inside the spread.4Hidden orders are limit orders completely nonobservable to other market participants.They have become increasingly popular in the past five years or so and are allowed by many stock exchanges around the world nowadays. This learning on hidden orders through pinging would enable HFTs to ascertain the existence of potential large trading interest in the market. Consequently, they would be able to trade ahead and capture a price movement in the direction of the large trading interest.6

------------------------------------------------------------------

However, despite the large amount of empirical evidence on pinging activities, few studies have shown how they can arise as a result of the optimal trading behaviors of HFTs. Given the public speculations and concerns surrounding such pinging activities, it is instructive to have an understanding on the nature of these activities, and my paper attempts to address this issue from a theoretical perspective.

In this paper, I aim to rationalize the pinging activity levels observable in the data through a theoretical setup without manipulative elements. It develops a continuous-time. model of the optimal trading strategies of HFTs absent any learning or strategic feedback effects. The model exploits two well-known forces in the existing literature: inventory control (e.g., Ho and Stoll (1981)) and momentum (trend) chasing (e.g., Hirschey (2013))

To achieve my purpose, I first incorporate the existence of hidden orders inside the bidask spread into a continuous-time model along the lines of Ho and Stoll (1981). As a result, the HFT in my model would ping for hidden orders inside the spread as a cheaper way to control his inventory compared to using market orders. This would produce pinging orders that execute against hidden orders.However,with inventory control as the sole motive for pinging, it is not possible to obtain a large number of cancelled pinging orders at the same time. The reason is that when the HFT uses pinging to control his inventory, he intends to fill his pinging orders and is not incentivized to cancel many of them.

To tackle this problem, I then introduce short-term price momentum into the model as a channel for cancelled pinging orders to occur. The momentum is modelled through the predictive power of depth imbalances for the directions of price movements. When the HFT sees a large depth imbalance and anticipates a likely directional price move,he could use pinging orders as directional bets to chase the price momentum. Moreover, if there is a subsequent large change in the depth imbalance, the HFT would cancel his pinging orders and adjust his strategy according to the variation in the price momentum.Hence the model will now give rise to both submissions and cancellations of pinging orders because of the HFT's momentum-chasing behaviors

------------------------------------------------------------------

The model is solved numerically because of the number of state variables,and I use historical order book message feed data from NASDAQ to reconstruct limit order books and estimate model parameters.7The optimal HFT strategies are characterized based on the viscosity solution to my model and the model parameter estimates.8There are two main findings. First, for stocks whose order books have high depths with relatively stable movements and whose spreads tend to be narrow,approximately $20\%$ of theHFT's optimal strategies are attributable to pinging. On the other hand, for stocks that tend to have low order-book depths, volatile order-book movements and wide spreads, pinging accounts for nearly $50\%$ of the HFT's optimal strategies. These pinging percentages from the model are proven to match over $70\%$ of the observable pinging activities in the data. Thus it implies that the pinging occurrences observed in reality can be mostly rationalized by my model without any learning or manipulative components

Second,I show that the mechanism of momentum chasing plays a much more important role than that of inventory control in rationalizing pinging activities for low-depth and wide spread stocks. In contrast, the two mechanisms carry around similar weights in rationalizing pinging activities for high-depth and narrow-spread stocks. Moreover, both mechanisms are proven to be necessary for the model to rationalize the pinging activities found in the data.

The result here in this paper that HFTs' pinging activities can be rationalized in a dynamic model without manipulation is reminiscent of the finding by Baruch and Glosten (2013). They demonstrate in a repeated-game setting that fickering quotes (rapid submissions and cancellations of limit orders) are an equilibrium outcome without manipulation. Their idea is that limit-order traders use flickering quotes to mitigate the undercutting risk of their orders when providing liquidity to the market, hence flickering quotes are not the result of these traders trying to manipulate the market.

However,my model differs from Baruch and Glosten (2013)'s in twofold. First, the

------------------------------------------------------------------

HFT's motives of pinging are diferent. In my model, the HFT uses pinging not because he is concerned about his limit orders being undercut,but rather to control his inventory or chase the price momentum. Second, and more importantly, my model offers an explanation on how the HFT's pinging behaviors would change across different types of stocks because of the variations in the HFT's optimal trading strategies. This result is not seen in Baruch and Glosten (2013). Therefore, my model not only gives a rationale for the empirical findings in Hasbrouck and Saar (2009, 2013), but also shows how the inventory-control and momentumchasing incentives of HFTs can lead to different pinging activities among stocks. This is my main contribution to the literature.

Beyond pinging rationalization, my model also generates a couple of additional auxiliary predictions. They concern about the directions of pinging activities and the frequencies of cancelled pinging activities with regard to the depth imbalances of order books. These predictions are also found to be largely consistent with the data, which further suggests that pinging is rationalizable as part of the dynamic trading strategies of HFTs.

The paper is organized as follows. I describe the related literature in Section 2. I show the model and my numerical solution in Section 3 and 4. Parameter estimations are depicted in Section 5. I present and discuss the main findings in Section 6. Finally, Section 7 concludes

# 2Related Literature

There is an important line of empirical studies (see, e.g., Brogaard, Hagstromer, Norden. and Riordan (2014), Brogaard, Hendershott, and Riordan (2014), Hagstromer and Norden (2013), Hasbrouck and Saar (2013), Hendershott and Riordan (2013), Hendershott, Jones, and Menkveld (2011） and Menkveld (2013) that try to understand the effects of highfrequency and algorithmic trading activities on market quality

On one hand, the majority of the empirical studies show that, on balance,HFTs are beneficial for market quality. For instance, Brogaard, Hendershott, and Riordan (2014) find

------------------------------------------------------------------

that HFTs enhance price discovery and market efficiency on NASDAQ. Hasbrouck and Saar (2013) also show that increased HFTs' low-latency activities are associated with lower posted and effective spreads, lower short-term volatility and increased market depth. Additionally, Hendershott, Jones, and Menkveld (2011) find that algorithmic tradings improve liquidity and make quotes more informative for NYSE stocks.

On the other hand, there are empirical analyses demonstrating that some HFT strategies are speculative and anticipatory in nature. For example, Hirschey (2013) finds that HFTs on NASDAQ tend to anticipate future order fows and trade ahead of them by taking liquidity from the market. Moreover, Kirilenko, Kyle, Samadi, and Tuzun (2014) show that HFTs exacerbated market volatility during the Flash Crash by trading in the direction of the downward price spiral. In addition, Baron, Brogaard, and Kirilenko (2014) find that aggressive. liquidity-taking HFTs earn short term profits at the expense of other market participants.

This paper focuses on the optimal trading strategies of HFTs and their pinging activities in particular, and attempts to show that such activities are rational and non-manipulative. It builds on the work of Ho and Stoll (1981), Avellaneda and Stoikov (2008), and Guilbaud and Pham (2013). In their models, an HFT performs the role of a pure market maker by optimally posting limit orders in the market. When allowed, the HFT would trade via market orders solely for the purpose of inventory control.

Compared to these previous configurations, my model makes two contributions. Firstly, hidden orders are introduced into the limit order book. Hence the HFT can ping to take the hidden liquidity when his limit orders improve the best bid or ask prices and are submitted inside the spread. This captures the idea of pinging strategies as identified in Hasbrouck and Saar (2009)’s empirical study. Secondly, I model the order book's depth imbalance at the best quotes as a stochastic process that can forecast the movement of the mid-price and the existence of hidden orders. Thus the HFT can use the depth imbalance as an imperfect signal to anticipate the likely price movement. Therefore, the HFT will utilize pinging or market orders to conduct directional tradings and chase the short-term price momentum.

------------------------------------------------------------------

This captures the idea of anticipatory strategies as identified in Hirschey (2013)

Since market orders are impulse controls in continuous time, the value function of the HFT in my model is not necessarily differentiable or even continuous everywhere.Thus I will apply the viscosity solution technique to my model. The viscosity solution concept, originated in Crandall and Lions(1983),is a generalization of the classical solution concept to Hamilton-Jacobi-Bellman equations (or partial differential equations in general) where value functions might not be everywhere differentiable or continuous.Iwill discuss the setup of my model and its solution in detail in the next two Sections.

## 3The Model

The economy is defined in a continuous-time, finite horizon ${\mathcal T}=[0,T]$ . There is a highfrequency trader (HFT) who trades a single risky stock in a limit order book (LOB)using either limit or market orders.The LOB has a tick size $\delta$ ,so that prices of all orders are in multiples of $\delta$ 9Characteristics of the LOB,such as the spread and the mid-price,evolve stochastically and are exogenous to the HFT.10

## 3.1Processes of Limit Order Book Characteristics.

I will fix a filtered probability space $(\Omega,\mathcal{O},\mathbb{D},\mathbb{P})$ ， $\mathbb{D}=(\mathcal{O}_{t})_{t\geq0}$ satisfying the usual conditions, so that all stochastic processes and random variables are defined on $(\Omega,\mathcal{O},\mathbb{D},\mathbb{P})$

------------------------------------------------------------------

To start with, the depth imbalance $F$ at the best quotes is defined to be the log of the size of the depth at the best bid price minus that at the best ask price, so that $F>0$ ( $F<0$ means bid (ask)side imbalance.It follows an Ornstein-Uhlenbeck process with mean zero

$$dF_t=-\alpha_F\:F_t\:dt+\sigma_F\:dW_t\:,$$

where $W$ is a standard Brownian motion, $\alpha_{F}$ measures the speed of mean-reversion and $\sigma_{F}$ is a constant volatility parameter

Next, let

$$S=\{S_t\}_{t\geq0}$$

denote the bid-ask spread of the LOB.It follows a continuous-time Markov chain on the state space ${\mathbf{S}}=\{\delta,2\delta,3\delta\}$ with a constant jump intensity $\lambda^{S}$ .The probability transition matrix of S is denoted by $\rho=(\rho_{ij})_{1\leq i,j\leq3}$ ,with $\rho_{ii}=0$

Furthermore, the mid-price $P$ of the stock is assumed to follow a pure jump process:

$$dP_t=dJ_{1t}+dJ_{2t}\:,\:P_t\in\mathcal{P}\:\mathrm{and}\:\mathcal{P}=\frac{\delta}{2}\cdot\mathbb{N}^+\:.$$

The first component, $J_{1t}$ ,has a constant jump intensity $\lambda_{1}^{J}$ and jump sizes equal to $\delta/2$ and $-\delta/2$ with probabilities $\psi_{1}(F_{t})$ and $1-\psi_{1}(F_{t})$ respectively. The second component, $J_{2t}$ ,has a constant jump intensity $\lambda_{2}^{J}$ and jump sizes equal to $\delta$ and $-\delta$ with probabilities $\psi_{2}(F_{t})$ and $1-\psi_{2}(F_{t})$ respectively.11 The functions $\psi_{i}:\mathbb{R}\mapsto[0,1]$ are assumed to have the form

$$\psi_{i}(u)=1/(1+\exp(-\beta_{i}\:u)),\quad\mathrm{for}\:i=1,2\:,$$

where $\beta_{1},\beta_{2}$ are positive constants. In addition, $J_{1}$ and $J_{2}$ are independent. This means the

------------------------------------------------------------------

depth imbalance $F$ is a predictor of the directions of mid-price jumps.The reason is that the depth imbalance is informative about whether the depth at the best bid or ask is likely to become depleted first,leading to a mid-price change.Thus it is a signal for the HFT to forecast the direction of a future price movement

The influence of the imbalance $F$ on the directions of the mid-price jumps is interpreted as the short-term price momentum.If the parameter $\sigma F$ is large so that $F$ is volatile,it leads to more frequent appearances of strong momentum (signals). Thus the HFT is more likely to engage in trend-chasing actions. This effect is amplified if the jump intensities $\lambda_{1}^{J}$ and $\lambda_{2}^{J}$ of the mid-price are higher, i.e. there are more realizations of the price momentum.

Besides these LOB variables, orders with limited pre-trade transparency have become increasingly popular on electronic trading platforms recently. Major US stock exchanges, such as NASDAQ and NYSE, permit submissions of hidden limit orders into their LOBs.12 The price, size and location of these orders are completely concealed from other market participants, and they can be placed inside the observable bid-ask spread without affecting the visible best bid and ask quotes.This mechanism of hidden orders has led to a vast number of order activities as HFTs try to “ping” for hidden liquidity inside the spread by posting aggressive “feeting orders” that are cancelled a few instants later if not executed.13

To account for this phenomenon, I will specify the existence of hidden orders inside the spread as follows. If the spread $S_{t}=2\delta$ ，the probability of hidden bid orders sitting at $P_{t}$ is $\varphi_{1}(F_{t})$ and that of hidden ask orders at $P_{t}$ is $\pi_{1}-\varphi_{1}(F_{t})$ .Similarly, if $S_{t}=3\delta$ ，the probabilities of hidden bid orders at $P_{t}-\delta/2$ and $P+\delta/2$ are $\varphi_1(F_t)$ and $\varphi_{2}(F_{t})$ respectively so that those of hidden ask orders at $P_{t}-\delta/2$ and $P_{t}+\delta/2$ are $\pi_{1}-\varphi_{1}(F_{t})$ and $\pi_{2}-\varphi_{2}(F_{t})$ 1 Since the existing literature suggests that the probability of hidden orders inside the spread

------------------------------------------------------------------

is positively correlated with the own-side depth imbalance, I let the functions $\psi_{i}$ be

$$\varphi_{i}(u)=\pi_{i}/(1+\exp(-\kappa\:u)),\quad\mathrm{for}\:i=1,2\:,$$

where $Fu$ and $71i$ are positive constants and $\pi_{i}<1$ 15 When 711 and 712 are large,hidden orders aremorelikely to be foundwithin the spread

## 3.2 The HFT's Trading Strategies

At any time $t$ ，the HFT can submit limit buy and sell orders,which will be executed only when they are filled by incoming market orders.The quantity of the HFT'slimit orders is fixed at one lot (100 shares).16 Alternatively, the HFT can send out market buy or sell orders trading at thebest availableprice on the opposite sidefor animmediate execution

### 3.2.1Make Strategy

When using limit orders (a make strategy)， the HFT can place his orders at the best available bid and ask prices, hence joining the existing order queues at these prices.17 This simply amounts to the traditional market-making behavior,which means that the HFT tries to passively capture the spread by posting limit orders at the best available quotes

Furthermore, the HFT can also“ping”inside the spread by improving either the best bid or ask price by one tick whenever the spread $S_{t}$ is greater than $\delta$ ,i.e. submitting a buy (sell) limit order at $P_{t}-S_{t}/2+\delta\:(P_{t}+S_{t}/2-\delta)$ .Such actions are done by HFTs in practice not only to capture the market order fow at the best quotes, but also to ping for hidden orders

------------------------------------------------------------------

inside the spread (Hasbrouck and Saar (2009)). However, despite faster executions, these pinging limit orders receive worse execution prices than their queuing counterpart.

Because the submission, update or cancellation of limit orders entails no cost, it is natural to model the make strategy of the HFT as a continuous-time predictable control process:

$$\theta_t^{mk}=\{\theta_t^{mk,b},\theta_t^{mk,a}\}\:,t\geq0,$$

where $\theta_{t}^{mk,b}\in\{0,1\}$ and $\theta_{t}^{mk,a}\in\{0,1\}$ . $b$ and $d$ stand for the bid and the ask side respectively. The predictable processes $\theta_{t}^{mk,b}$ and $\theta_{t}^{mk,b}$ : with values equal to 0 or 1 : represent the possible make strategy regimes: 0 indicates that the limit order is joining the queue at the best price whereas 1 indicates the limit order is improving the best price by $\delta$ .Note that if the spread is at its minimum $\delta$ ， $\theta_{t}^{mk,b}$ and $\theta_{t}^{mk,b}$ both can only take the value of 0 , since improving the best bid or ask then will simply be considered as posting a market buy or sell order instead.

## 3.2.2 Take Strategy

Instead of limit orders, the HFT may also employ market orders (a take strategy） to obtain instant executions. However, unlike limit orders, market orders take liquidity from the LOB and are subject to a transaction fee of $t$ per share.The costly nature of market orders means that,if a take strategy is used continuously, the HFT will go bankrupt in finite time. Thus I will model the HFT's take strategy as an impulse control in continuous time:

$$\theta^{tk}=\{\tau_n,\:\zeta_n\}_{n\in\mathbb{N}}\:.$$

Here, $\{\tau_{n}\}$ is an increasing, finite sequence of stopping times indicating the times when the HFT uses market orders, and $\zeta_{n}\in[-\zeta_{max},\zeta_{max}]\backslash\{0\}$ are $\mathcal{F}_{\tau_{n}}$ -measurable random variables denoting the number of shares (in lot size) bought ( $\zeta_{n}>0$ ) or sold ( $\zeta_{n}<0$ )at these times. I restrict the market order sizes to be less than some small constant $\zeta_{max}$ , so that the HFT

------------------------------------------------------------------

remains small relative to the market and his market orders do not eat through the LOB.18

### 3.3Order Execution Processes

For the HFT's limit orders submitted at the best bid and ask, they will be executed only if counterpart market orders arrive in the next instant and fill them completely.Imodel the arrivals of exogenous buy and sell market orders by two independent Poisson processes, $M^{b}$ (for buy) and $M^{a}$ (for sell),with intensities given by $\lambda^{b}$ and $\lambda^{a}$ respectively.In addition, when a buy (sell) market order arrives, the HFT's sell (buy) limit order in the queue will be filled with a probability given by the fill-rate function $h(F_{t})$ $h(-F_{t})$ ),where

$$h(u)=1/(1+\exp(\varsigma_0+\varsigma_1\:u)),\:\varsigma_0,\:\varsigma_1\:\text{are positive constants.}$$

This fill-rate function depicts the idea that the probability of execution for a queuing limit order becomes higher (lower） if the own-side queue is relatively shorter (longer)，which illustrates the time priority structure of the LOB.

However, if a limit order jumps the queue instead (i.e. pings inside the spread), it will be executed instantly as long as there is a matching hidden order from the opposite side that resides inside the spread. Otherwise, this limit order will be fully matched if a counterpart market order arrives at the next moment, due to its time priority

Turning to the HFT's market orders, they involve a fixed transaction fee of $t$ per share, but they will execute immediately by hitting either hidden orders inside the spread or limit orders at the best price on the opposite side

## 3.4Comments on the Model

There are two important aspects of the model that are new compared to the current literature on HFT strategies and are essential for rationalizing HFTs’pinging activities without

------------------------------------------------------------------

manipulation or learning. First, the use of limit orders to capture hidden liquidity has not been properly addressed in existing continuous-time models of HFTs,where the limit order strategy of the HFT is for market-making purposes only. In my model, limit orders can also be utilized by the HFT as a “pinging” strategy, due to the existence of hidden orders inside the spread. Compared to the traditional market-making behavior, pinging is more aggressive as it seeks a faster execution at a less favorable price. However, it is not as aggressive as using market orders since it does not cross the spread. Given the large number of pinging activities identified in empirical work (e.g., Hasbrouck and Saar (2009, 2013)), it is essential to include hidden orders and pinging strategies in a theoretical model of HFT behaviors.

Another aspect that has not been fully dealt with in the continuous-time literature concerns directional or momentum tradings by HFTs. In a standard setup, an HFT would use market orders only for inventory control purposes. However, in my model, the HFT would also implement market orders as a momentum strategy to aggressively take liquidity from the market and trade directionally when the price momentum is strong enough.There are empirical studies that have identified some most profitable HFTs as primarily liquidity takers (e.g., Baron, Brogaard, and Kirilenko (2014)) and have recognized the anticipatory and directional trading behaviors of HFTs (e.g., Hirschey (2013). Hence it is crucial to incorporate momentum (directional) tradings into any theoretical models on HFT strategies.19

When both hidden orders and price momentum exist in the model, the HFT has two motives to carry out pinging strategies. One is to control the inventory. The HFT can ping inside the spread to hit hidden orders when he needs to unwind his inventory, which is cheaper than using market orders. Nonetheless, if hidden orders existed with high probabilities 711 and 712 and inventory control was the HFT's only motive for pinging, the model would generate a large number of pinging orders filled by hidden orders. There will not be many cancelled pinging orders at the same time, contradicting with the numerous ones observed in reality

The existence of the price momentum is then necessary to bring about cancelled pinging

------------------------------------------------------------------

activities, because now the other motive for the HFT to ping is to chase price trends. The HFT can use pinging orders to establish directional positions when anticipating a likely price move. However, if the volatility parameter $0F$ is large so that the depth imbalance (momentum) varies turbulently, it would induce the HFT to cancel his pinging orders frequently and change his strategies based on the momentum swings. This is escalated if the mid-price jump intensities $\lambda_{1}^{J}$ and $\lambda_{2}^{J}$ are also large. Large intensities prompt more trend-chasing pinging activities from the HFT as his directional bets have a higher chance to materialize, yet the HFT often needs to cancel his pinging orders due to volatile changes in the price momentum.

# 4 Equilibrium and Solution Method

# 4.1Objective of the HFT

To derive the equilibrium of my model, I begin by stating the cash holding and the inventory processes of the HFT, and then define his optimization problem

Let $X$ and $Y$ denote the cash holding and the inventory of the HFT. If a (limit order) make strategy $\theta_{t}^{mk}$ is used at $t$ , the cash holding $X$ and the inventory $Y$ evolve according to:

$$\begin{aligned}
&dY_{t} =d\widetilde{M}_{t}^{a}-d\widetilde{M}_{t}^{b} \\
&dX_{t} =-\:\left(P_{t}-\frac{S_{t}}{2}+\delta\theta_{t}^{mk,b}\right)d\widetilde{M}_{t}^{a}+\left(P_{t}+\frac{S_{t}}{2}-\delta\theta_{t}^{mk,a}\right)d\widetilde{M}_{t}^{b}\:, 
\end{aligned}$$

where

$$\begin{gathered}
d\widetilde{M}_{t}^{o} =\theta_{t}^{mk,b}\Big(B_{t}^{a}dt+(1-B_{t}^{a})dM_{t}^{a}\Big)+(1-\theta_{t}^{mk,b})h(F_{t})dM_{t}^{a} \\
d\widetilde{M}_{t}^{b} =\theta_{t}^{mk,a}\biggl(B_{t}^{b}dt+(1-B_{t}^{b})dM_{t}^{b}\biggr)+(1-\theta_{t}^{mk,a})h(-F_{t})dM_{t}^{b}\:. 
\end{gathered}$$

Here, $B_{t}^{a}$ ( $B_{t}^{b}$ ) is an indicator for whether ask (bid) hidden orders exist inside the spread. $B_{t}^{a}$ and $B_{t}^{b}$ have distributions $\eta^{a}(F_{t},S_{t})$ and $\eta^{b}(F_{t},S_{t})$ . $\eta^{a}$ n $\eta^{a}\left(\eta^{b}\right)$ matches the existence probability

------------------------------------------------------------------

of ask (bid) hidden orders at the best bid (ask) price plus $\delta$ given $F_{t}$ and $S_{t}$ .Thus when the HFT's buy (sell) limit order joins the queue at the best bid (ask), its inventory increases (decreases)by one lot if sell (buy) market orders arrive at the next instant and fill the HFT's limit order. Alternatively,if the HFT's buy (sell) limit order is pinging inside the spread, its inventory increases (decreases） by one lot whenever the limit order hits an opposite-side hidden order. Otherwise, it rises (falls) by one lot if sell (buy) market orders arrive within the next instant.The cash holding thus increases (decreases)by an amount equal to the quoted price of the sell (buy) limit order multiplied by the order's uncertain execution state.

On the other hand,the dynamics of $X$ and $Y$ jump at $t$ if the HFT exercises a(market order) take strategy $\theta_{t}^{tk}$ instead

$$\begin{aligned}
&Y_{t} =Y_{t-}+\zeta_{t}\:, \\
&X_{t} =X_{t-}-\Big[\:\zeta_{t}P_{t}+|\zeta_{t}|\Big(\frac{S_{t}}{2}-H_{t}+\epsilon\Big)\:\Big] 
\end{aligned}$$

where $t$ is the fixed fee per share for market orders, $H_{t}$ is an integer random variable with a probability mass function $G(\cdot\mid F_{t},S_{t})$ that takes the value of

$$H_t=\begin{cases}0&\text{if }S_t=\delta\\\\\delta&\text{if }S_t>\delta\text{ and the market order hits a hidden order at }P_t+sign(\zeta_t)\Big(\frac{S_t}{2}-\delta\Big)\\\\2\delta&\text{if }S_t>2\delta\text{ and the market order hits a hidden order at }P_t+sign(\zeta_t)\Big(\frac{S_t}{2}-\delta\Big)\end{cases}$$

and the distribution of $H_{t}$ matches the existence probabilities of the inside-spread hidden orders given $F_{t}$ and $S_{t}$ .Hence when the HFT submits a market order, its inventory $Y$ jumps up or down at $t$ by the size of the order. Moreover, its cash holding $X$ changes by the value of the order $\zeta_{t}P_{t}$ plus the cost associated with the market order. The cost consists of the uncertain part due to crossing the spread $(S_{t}/2-H_{t})$ and the fixed transaction fee $t$ 20

------------------------------------------------------------------

The objective of the HFT is to maximize over the finite horizon $[0,T]$ the cash earnings from his trades in the LOB and at the same time keep his inventory at bay.In addition, the HFT has to liquidate all his inventory at $I^{\prime}$ .Hence the HFT's optimization problem is

$$\max\limits_{\{\theta^{mk},\theta^{tk}\}}\:\mathbb{E}_{0}\left[X_{T}-\gamma\int_{0}^{T}Y_{t-}^{2}d[P,P]_{t}\right],\quad s.t.\:Y_{T}=0,$$

where the maximization is taken over all admissible strategies $\Theta$ 21 The term $\gamma\int_{0}^{T}Y_{t-}^{2}d[P,P]_{t}$ is a quadratic-variation penalization term for holding a nonzero inventory in the stock,where $\gamma>0$ is a penalization parameter and $[P,P]_{t}$ is the quadratic variation of the mid-price $P$

I can rewrite the above optimization problem with the constraint $Y_{T}=0$ removed. To this end, I introduce the function

$$Q(x,y,p,f,s)=x+py-|y|\biggl(\frac{s}{2}-H+\epsilon\biggr)\:,$$

which represents the total cash obtained after an immediate liquidation of the inventory $y$ via a market order,given the cash holding $JL$ ，the mid-price $P$ the depth imbalance $f$ and the spread S 22I cannow reformulate the problem (16)equivalently as

$$\max_{\{\theta^{mk},\theta^{tk}\}}\:\mathbb{E}_{0}\left[X_{T}+P_{T}Y_{T}-|Y_{T}|\Big(\frac{S_{T}}{2}-H_{T}+\epsilon\Big)-\gamma\int_{0}^{T}Y_{t-}^{2}d[P,P]_{t}\right]\:.$$

The proofs for all lemmas and propositions are shown in the Appendix

## Lemma 1. (16) and (18) are equivalent

Having defined the objective,the value function ofproblem(18)for theHFT is then

$$(t,x,y,p,f,s)=\sup_{\{\theta^{mk},\theta^{tk}\}}\mathbb{E}_{t}\left[X_{T}+P_{T}Y_{T}-|Y_{T}|\Big(\frac{S_{T}}{2}-H_{T}+\epsilon\Big)-\gamma\int_{t}^{T}Y_{u-}^{2}d[P,P]_{u}\right]$$

for $\{\theta^{mk}$ ， $\theta^{tk}\}\in\Theta$ ， $t\in[0,T]$ , and $(x,y,p,f,s)\in\mathbb{R}^{2}\times\mathcal{P}\times\mathbb{R}\times\mathbb{S}$ .Here, given {gmk $\{\theta^{mk}$ $\{\theta^{mk},\:\theta^{tk}\}\in\Theta$

------------------------------------------------------------------

$\mathbb{E}_t$ denotes the expectation operator under which the solution $(X,Y,P,F,S)$ to the processes (1)-(3) and (9)-(14), with initial state $(X_{t-},Y_{t-},P_{t-},F_{t-},S_{t-})=(x,y,p,f,s)$ ,is taken

Before defining the model's equilibrium, I state the following lemma, which demonstrates that the value function is finite and locally bounded.

Lemma 2.There erists some constant $C_{0}$ and $C_{1}^{r}$ such that for all $(t,x,y,p,f,s)\in[0,T]\times$ $\mathbb{R}^2\times\mathcal{P}\times\mathbb{R}\times\mathbb{S}$

$$Q(x,y,p,f,s)\leq V(t,x,y,p,f,s)\leq x+py+C_0+C_1\:.$$

Both bounds have an intuitive financial interpretation. The lower bound is the value from the particular strategy that eliminates all non-zero inventory through a market order, and then does nothing until the time reaches $T$ .The upper bound is made of three terms. The first term, $x+py$ , is the value of the HFT's cash holding plus his inventory evaluated at the mid-price. The second constant $C_{0}$ is the upper bound on the profit from the fictitious traditional market-making strategy that participates in every trade without any cost of controlling the inventory. The last constant $C_{1}^{\prime}$ denotes a bound on the profit from any directional costless market order strategy on a virtual asset always priced at the mid-price.

# 4.2 Equilibrium and Dynamic Programming Equations

The problem of (19) is a mixed regular-impulse stochastic control problem in a jumpdiffusion model, and I will use dynamic programming to characterize the model's equilibrium. To this end, I introduce two mathematical operators. For any admissible (limit order) make strategy $\theta^{mk}=\left\{\theta^{mk,b},\theta^{mk,a}\right\}$ , I will define the second-order non-local operator $L$

$$\begin{aligned}
\mathcal{L}\circ V(t,x,y,p,f,s)& =(\mathcal{L}^{P}+\mathcal{L}^{F}+\mathcal{L}^{S})\circ V(t,x,y,p,f,s)  \\
&+g^{a}(f,s,\theta_{t}^{mk,b})\cdot V\Big(t,\:x-(p-s/2+\delta\theta_{t}^{mk,b}),\:y+1,\:p,\:f, \\
&+g^{b}(f,s,\theta_{t}^{mk,a})\cdot V\big(t,\:x+(p+s/2-\delta\theta_{t}^{mk,a}),\:y-1,\:p,\:f,
\end{aligned}$$

------------------------------------------------------------------

where $\mathcal{L}^{P}$ ， $\mathcal{L}^{F^{\prime}}$ ， $\mathcal{L}^{S}$ in the first term are the infinitesimalgenerators for the processes of the mid-price $P$ .the depth imbalance $F$ andthe spread $S$ respectively,and the next two terms are the non-local operators induced by the expected changes of the cash holding process $X$ and the inventory process $Y$ when the HFT applies a make strategy $\theta_{t}^{mk}$ at $t$ .In addition,

$$g^{a}(f,s,\theta_{t}^{mk,b})=\theta_{t}^{mk,b}\big(\eta^{a}(f,s)+(1-\eta^{a}(f,s))\lambda^{a}\big)+(1-\theta_{t}^{mk,b})\lambda^{a}h(f)\\g^{b}(f,s,\theta_{t}^{mk,a})=\theta_{t}^{mk,a}\big(\eta^{b}(f,s)+(1-\eta^{b}(f,s))\lambda^{b}\big)+(1-\theta_{t}^{mk,a})\lambda^{b}h(-f),$$

which are the expected execution rates for the HFT's bid and ask limit orders respectively.2

The impulse control operator $M$ for an admissible (market order) take strategy $\theta^{tk}$ is

$$\begin{aligned}
&\mathcal{M}\circ V(t,x,y,p,f,s) \\
&=\operatorname*{sup}_{\zeta\in[-\zeta_{max},\:\zeta_{max}]}\:\int_{H}V\big(t,\:x-\zeta p-|\zeta|(s/2-H+\epsilon),\:y+\zeta,\:p,\:f,\:s\big)\:dG(H\:|\:s,f)\:,
\end{aligned}$$

which is generated by the jumps in $X$ and $Y$ due to $\theta_{t}^{tk}$ being used at $t$

With $L$ and ${\mathcal{M}}$ defined, the dynamic programming equation associated with the value function (19) is the Hamilton-Jacobi-Bellman quasi-variational inequality (HJB-QVI)

$$\max\:\left\{\frac{\partial V}{\partial t}+\sup\limits_{\{\theta^{mk}\}}\:\{\mathcal{L}\circ V\}-\gamma y^2\frac{\mathbb{E}_td[P,P]_t}{dt}\:,\:\mathcal{M}\circ V-V\right\}=0,\:\text{on}\:[0,T)$$

together with the terminal condition

$$V(T,x,y,p,f,s)=x+py-|y|(s/2+\epsilon)+|y|\int_{H}H\:dG(H\:|\:s,f)\:.$$

The next lemma shows that the HJB-QVI(25)has a well-defined expression by giving the full expressions for the infinitesimal generators CP $\mathcal{L}^{P}$ $\mathcal{L}^{F^{\prime}}$ CF $({\mathcal L}^{P},{\mathcal L}^{F},{\mathcal L}^{S})$ CS $\mathcal{L}^{S}$ and the value of $\mathbb{E}_{t}[P,P]_{t}$ Lemma 3. The HJB-QVI (25) admits a well-defined expression

------------------------------------------------------------------

I then present the equilibrium concept of my modelin the following definition

Definition 1.In the above economy where the HFT trades a risky stock in anLOB governed by the stochastic processes laid out in Section 3.1-3.3, the partial equilibrium is defined by a value function $v(t;\bullet)$ and policy functions (strategies) $\{\theta^{mk},\:\theta^{tk}\}_{t}$ gtk}t $\theta^{tk}\}_{t}$ ， $t\in[0,T]$ ，such thai

(a）The policy functions solve the HFT's maximization problem (18);

(b) Given the policy functions, the value function $V$ solves the HJB-QVI (25) for $t\in[0,T)$ with the terminal condition (26) at 7

The next proposition shows that a solution to the partial equilibrium exists and is unique

Proposition 1.There erists a unique solution to the partial equilibrium of the model.In particular, the value function in (19) is the unique viscosity solution to (25) and (26).24

Before providing a numerical solution to the equilibrium of mymodel,I present a lemma that simplifies the value function (19) and reduces its dimensionality

Lemma 4. The value function 19)can be decomposed as

$$V(t,x,y,p,f,s)=x+py+\nu(t,y,f,s).$$

Moreover, the reduced-form value function $V$ satisfies the quasi-variational inequality and the terminal condition shown below, which are simplified from (25-(26) after decomposing $V$

$$\begin{gathered}
\operatorname*{max}\:\left[{\frac{\partial\nu}{\partial t}}+y{\frac{\mathbb{E}_{t}dP_{t}}{dt}}+\mathcal{L}^{\mathcal{F}}\circ\nu+\mathcal{L}^{\mathcal{S}}\circ\nu-\gamma y^{2}{\frac{\mathbb{E}_{t}d[P,P]_{t}}{dt}}+\right] \\
\sup\limits_{\theta^{mk}}\left\{g^{a}(f,s,\theta_{t}^{mk,b})\cdot\left(\nu(t,y+1,f,s)-\nu(t,y,f,s)+s/2-\delta\theta_{t}^{mk,b}\right)+\right\} \\
g^b(f,s,\theta_t^{mk,a})\cdot\left(\nu(t,y-1,f,s)-\nu(t,y,f,s)+s/2-\delta\theta_t^{mk,a}\right)\Bigg\}\:, \\
\sup_{\zeta}\left\{\nu(t,y+\zeta,f,s)-|\zeta|(s/2+\epsilon)+|y|\int_{H}H\:dG(H\:|\:s,f)\right\}-\nu  
\end{gathered}$$

------------------------------------------------------------------

with the terminal condition:

$$\nu(T,y,f,s)=-|y|(s/2+\epsilon)+|y|\int_{H}H\:dG(H\:|\:s,f)\:.$$

## 4.3Numerical Solution

For the numerical solution to the value function $V$ of (19)，since $V(t,x,y,p,f,s)=$ $x+py+\nu(t,y,f,s)$ , I will provide a backward, finite-difference scheme that solves the quasivariational inequality 28) and the terminal condition (29). My method is based on the schemes developed by Chen and Forsyth (2008) and Guilbaud and Pham (2013)

First, I use a time discretization on $[0,T]$ with a step $\Delta_{T}=T/N_{T}$ and a regular grid

$$\mathbb{T}_{N_T}=\{t_k=k\Delta_T,k=0,\ldots,N_T\}\:.$$

Second, I discretize and localize the spaces for $Y$ and $F$ on two regular grids.withbounds $M_{Y},M_{F}$ , and steps $\Delta_{Y}=M_{Y}/N_{Y}\equiv1$ ， $\Delta_{F}=M_{F}/N_{F}$ ,where $N_{Y},N_{F}\in\mathbb{N}$ , so that

$$\mathbb{Y}_{N_{Y}}=\{y_{i}=i\Delta_{Y},i=-N_{Y},\ldots,N_{Y}\},\quad\mathbb{F}_{N_{F}}=\{f_{j}=j\Delta_{F},j=-N_{F},\ldots,N_{F}\}\:.$$

Next, I define two finite-difference matrices, $D_{1}$ and $D_{2}$ ，for calculating the first and the second order derivatives against $F$ on the grid $\mathbb{F}_{N_F}$ ，where $D_{2}$ uses central differences and $D_{1}$ uses forward differences when $f_{j}<0$ and backward differences when $f_{j}\geq0$ :2

$$\begin{aligned}
&D_{2}\nu(t,y,f_{j},s) =\frac{\nu(t,y,f_{j+1},s)-2\nu(t,y,f_{j},s)+\nu(t,y,f_{j-1},s)}{(\Delta_{F})^{2}}  \\
&D_{1}\nu(t,y,f_{j},s) =\begin{cases}\frac{\nu(t,y,f_{j+1},s)-\nu(t,y,f_j,s)}{\Delta_F}&\text{if}&f_j<0\\\\\frac{\nu(t,y,f_j,s)-\nu(t,y,f_{j-1},s)}{\Delta_F}&\text{if}&f_j\ge0\end{cases} 
\end{aligned}$$

------------------------------------------------------------------

I now state the main part of the numerical scheme. To this end, I introduce the explicit implicit operator for the time-space discretization of the quasi-variational inequality (28).1 define, for any $(t,p,f,s)\in[0,T]\times\mathcal{P}\times\mathbb{R}\times\mathbb{S}$ and any real-valued function $\phi:\mapsto\phi(t,y,f,s)$

$$\mathcal{A}(t,y,f,s,\phi)=\max\left\{\widetilde{\mathcal{L}}(t,y,f,s,\phi)\:,\:\widetilde{\mathcal{M}}\circ\widetilde{\mathcal{L}}(t,y,f,s,\phi)\right\},$$

where ;26

$$\begin{aligned}
\tilde{\mathcal{L}}(t,y,:,s,\phi)& =\left(I_{N_{F}\times N_{F}}-\Delta_{T}\sigma_{F}^{2}D_{2}-\Delta_{T}\alpha_{F}(\mathbb{F}_{N_{F}}\mathbf{1}_{N_{F}}^{\prime})...D_{1}\right)^{-1}\times \\
&\left(\phi(t,y,.,s)+\Delta_{T}y\frac{\mathbb{E}_{t}dP_{t}}{dt}+\Delta_{T}\mathcal{L}^{S}\left(\phi(t,y,.,s)\right)-\Delta_{T}\gamma y^{2}\frac{\mathbb{E}_{t}d[P,P]_{t}}{dt}+\right) \\
&\Delta_{T}\sup_{\theta^{mk}}\Big\{g^{a}(:,s,\theta_{t}^{mk,b})\odot\Big(\phi(t,y+1,:,s)-\phi(t,y,:,s)+\frac{s}{2}-\delta\theta^{mk,b}\Big)+ \\
&g^{b}(:,s,\theta_{t}^{mk,a})\odot\left(\phi(t,y-1,:,s)-\phi(t,y,:,s)+\frac{s}{2}-\delta\theta^{mk,a}\right)
\end{aligned}$$

and

$$\widetilde{\mathcal{M}}\circ\widetilde{\mathcal{L}}(t,y,f,s,\phi)=\operatorname*{sup}_{|\zeta|\leq\zeta_{max}}\:\left\{\widetilde{\mathcal{L}}(t,y+\zeta,f,s,\phi)-|\zeta|\left(\frac{s}{2}+\epsilon\right)+|y|\int_{H}H\:dG(H\mid s,\phi)\right\},$$

When the inventory $y$ is on the boundary of $\mathbb{Y}_{N_Y}$ Ny $NY$ ,i.e. $y=-M_{Y}$ or $y=M_{Y}$ ,make and take strategies are confined to the buy side or the sell side only, so that $y$ does not go off from its grid.Then, I approximate the solution $V$ to (28)-(29)by the numerical solution $uv$ on $\mathbb{T}_{N_{T}}\times\mathbb{Y}_{N_{Y}}\times\mathbb{F}_{N_{F}}\times S$ to the backward explicit-implicit finite difference scheme

$$\varpi(T,y,f,s)=-|y|(\frac{s}{2}+\epsilon)+|y|\int_{H}H\:dG(H\:|\:s,f)$$

$$\varpi(t_k,y,f,s)=\mathcal{A}(t_{k+1},y,f,s,\varpi),\:k=N_T-1,N_T-2,\ldots,0\:,$$

------------------------------------------------------------------

where (37) and (38) approximate (29) and (28)respectively

The complete solution algorithm is summarized in the backward induction steps below

1. At the terminal date $t_{N_{T}}=T$ : for each combination of $(y,f,s)$ ,make $\varpi(T,y,f,s)=$
$$-|y|(\frac{s}{2}+\epsilon)+|y|\int_{H}H\:dG(H\:|\:s,f).$$
2. (Backward Induction) From time step. $t_{k+1}$ to $t_{k}$ where $k$ runs from $N_{T}-1$ back to 0 for each combination of $(y,f,s)$ (a) Calculate ${\bar{\mathcal{L}}}(t_{k+1},y,f,s,\varpi)$ from (35） and obtain $\theta^{mk,*}$ (b) Calculate $\widetilde{\mathcal{M}}\circ\widetilde{\mathcal{L}}(t_{k+1},y,f,s,\varpi)$ from (36) and obtain $\theta^{tk,*}$
$$:\widetilde{\mathcal{L}}(t_{k+1},y,f,s,\varpi)\geq\widetilde{\mathcal{M}}\circ\widetilde{\mathcal{L}}(t_{k+1},y,f,s,\varpi),\mathrm{~set~}\varpi(t_{k},y,f,s)=\widetilde{\mathcal{L}}(t_{k+1},y,f,s,\varpi)$$
the policy(optimal strategy) at $t_k$ is thus $\theta^{mk,*}$ , given $(y,f,s)$ (d) Otherwise, let $\varpi(t_{k},y,f,s)=\widetilde{\mathcal{M}}\circ\widetilde{\mathcal{L}}(t_{k+1},y,f,s,\varpi)$ , and $\theta^{tk,*}$ is taken to be the policy (optimal strategy) at $t_{k}$ , given $(y,f,s)$

Finally,I state the theorem for the convergence of my numerical solution $UU$ to the reduced-form value function $V$ ，and hence the convergence of the discretized policy functions to the equilibrium optimal strategies

Proposition 2. The solution. $UU$ to the numerical scheme (37)-(38)and the corresponding discretized policy functions converge locally uniformly to the reduced-form value function $V$ and the equilibrium optimal strategies on $[0,T]\times\mathbb{R}\times\mathbb{R}$ a.8 $(\Delta_{T},\Delta_{Y},M_{Y},\Delta_{F},M_{F})\:\rightarrow$ $(0,0,\infty,0,\infty)$ ， $\forall s\in S$

## 5 Estimation

In order to quantify the optimal trading strategies of the HFT based on the numerical solution, I need to obtain values for the parameters that govern the stochastic processes of

------------------------------------------------------------------

the LOB variables. This Section concerns the estimation of these parameters. Panel (A) of Table 1 summarizes the parameters to be estimated.

## 5.1Data

I use NASDAQ TotalView-ITCH 4.0 limit order book message feed data on three types of stocks listed on NASDAQ during the month of June 2012 (21 trading days). The three types consist of stocks with narrow spreads and high order-book depths, stocks with medium spreads and depth levels, and stocks with wide spreads and low order-book depths. I focus on three representative stocks, with one from each of the three types: INTC (Intel, narrow spread and high depth), QCOM (Qualcomm, medium spread and medium depth), and AMZN (Amazon, wide spread and low depth)

The TotalView data include all real-time messages of limit order submissions, cancellations, executions and hidden order executions for all NASDAQ-listed stocks on every trading day from 7:00am EST when NASDAQ's electronic limit order book system starts accepting incoming limit orders. The messages are stamped to millisecond precision. The system is initialized by an empty order book where all overnight limit orders are resubmitted automatically at the beginning of each day. The data record a unique identification for each limit order and I can identify the attribute of a limit order (cancelled, executed or neither） by tracking it through its order ID. Moreover, trades are identified via the records of limit order and hidden order executions. Since the trading directions of limit orders and hidden orders are recorded, I can exactly identify whether a trade is buyer-initiated or seller-initiated. I consolidate all trade transactions into one single trade from a market order if they are logged at the same time-stamp in the data and have the same initiation type. Therefore, the LOB for any NASDAQ stock at any time can be reconstructed (up to millisecond precision) through continuously updating the book system according to all reported messages. Since the LOB variables of my model concern only the first level of the order book,I

track the evolutions at the top of the book for estimation purposes. As in common practices.

------------------------------------------------------------------

I use data between 9:45am and 15:45pm to avoid certain erratic market movements that are likely to occur at market openings or closures.

## 5.2Estimation

I will employ standard nonparametric estimators for all the intensity parameters and the transition matrix $\rho$ 27The parameters of the depth imbalance $F$ are estimated using the maximum likelihood method, since an Ornstein-Uhlenbeck process has an explicit transition density 28 In addition, the parameters governing various probabilities are estimated by logistic regressions, as these probability distribution functions all have logistic forms. I conduct the estimations for all trading days in June 2012, and then calculate the averages of these daily estimates as my final estimated parameter values to be fed into my numerical solutions The mean values of my daily parameter estimates are reported in Table 2, with Newey-West heteroskedasticity and autocorrelation consistent (HAC) standard errors in parentheses

The estimation results have three aspects that are worth noticing.Firstly, compared to Amazon,Intel and Qualcomm have a less volatile imbalance process $F$ aswell as ahigher tendency to stay at lower-spread positions. Secondly, due to its lower book depth, Amazon’s mid-price jumps occur more often, as measured by the larger values of both $\lambda_{1}^{J}$ and $\lambda_{2}^{J}$ for Amazon. Thirdly, the estimates of hidden order parameters, market order arrival rates and limit order fill rates are more alike for those three stocks.We will see next that these dissimilarities in the parameter estimates will lead to a much diferent quantification of the optimal HFT strategies for Amazon as opposed toIntel or Qualcomm.

Besides the estimated parameters, the fixed parameters in Panel (B) of Table 1 are also used in my numerical quantification and simulation study of the optimal HFT strategies

------------------------------------------------------------------

## 6 Computation and Simulation Results

In this Section,I provide numerical results on the optimal HFT strategies computed via the implementation of my numerical scheme (37)-(38),for the three representative stocks - Intel (INTC),Qualcomm QCOM) and Amazon (AMZN) 29 I use as inputs the estimatec parameter values shown in Table 2 and the fixed parameters listed in Panel (B) of Table 1.

## 6.1Percentage Attributions of Optimal Strategies

In this part,I conduct Monte Carlo simulations to quantify the properties of the HFT's optimal strategies for the three stocks:Intel,Qualcomm and Amazon.The number of simulations is set to be $N_{MC}=10000$ for each stock, and I use a standard Euler scheme to simulate the paths of the state variables $(P,S,F,X,Y)$ and the exogenous market order arrivals $(M^{b},M^{a})$

Table 3 summarizes the percentage attributions (averaged over simulations)of the optimal HFT strategies to three types of activity: traditional market making (submitting a limit order at the best available bid and ask prices) and inventory control (using market orders), pinging, and momentum (directional) trading via market orders. These percentages are calculated asfollows.For each one of the Monte Carlo simulations,I compute the number of strategy choices attributable to each type of the activity, which are optimally made given the numerical solution and the simulated state variables at each point on the simulated path. Then I divide these numbers by the total number of strategy-choosing points in a simulation, which equals $T/\Delta_{T}=7200$ , to arrive at the corresponding percentage attribution numbers for one simulation. Finally, I average those percentage numbers across all 1o000 simulations to obtain the percentage attributions shown in Table 3.

There are two main implications that we can learn from Table 3. Firstly, for stocks with

------------------------------------------------------------------

narrow spreads on average and abundant order book depths such as Intel, the HFT behaves like a market maker in the traditional sense. He is providing liquidity to the market most of the time. As a result, pinging activities account for only $20\%$ of the optimal strategies and approximately $70\%$ of the strategies are in the realm of liquidity provision (market making) and inventory management by market orders.

Secondly, for stocks like Amazon with wide spreads on average and an order book that has low depths and volatile movements, the HFT looks less like a passive market maker Instead, he acts more like an aggressive chaser for short-term price trends, since pinging and momentum trading together account for about $70\%$ of the strategies for Amazon.In particular, pinging constitutes nearly $50\%$ of the optimal strategies. Pinging is considered as a strategy that demands liquidity from the market when its objective is to build a directional inventory position.Hence for stocks with wide spreads and low book depths,the HFT is mainly a market taker and frequently taking liquidity to bet on the directional price moves.

Next, I compared the pinging percentages obtained from the model (as shown in Table 3) to the pinging percentages observable from the data to see how much pinging in the data can be rationalized by the model. To calculate pinging percentages in the data, I first compute the number of cancelled pinging activities for different stocks in a similar fashion to Hasbrouck and Saar (2009). This is defined as the number of limit orders submitted inside the spread and then cancelled in less than 2 seconds. Second, I need to compute the number of pinging orders that execute against hidden orders inside the spread. This is somewhat problematic since such pinging orders are identical to market orders that hit hidden orders. In order to deal with this issue, I treat non-consecutive orders executing on hidden orders as pinging orders.Therefore, the number of total pinging activities are calculated as the sum of the number of cancelled pinging activities and the number of pinging orders hitting hidden orders. I then divide the number of total pinging activities by the total number of

------------------------------------------------------------------

order book activities to arrive at the pinging percentages found in the data

$$\text{Pinging}\%\text{in the data}=\frac{\text{Number of total pinging activities}}{\text{Total number of order book activities}}.$$

Finally, the model’s pinging percentages are gauged against those from the data (expressed as a fraction of data's pinging percentage numbers) in Table 4.

As clearly seen from Panel (A) in Table 4, the pinging percentages produced by the model match quite closely to the percentages from the data.At least around $70\%$ of the pinging activities observable from the data can be captured by the model, and the number is higher for stocks with high depths and low spreads (like Intel). Hence the result indicates that most of the pinging activities found in the data can be rationalized by the model with the two mechanisms of inventory control and momentum chasing

Panel (B） in Table 4 further breaks down the roles that the mechanisms of inventory control and momentum chasing play in rationalizing pinging activities in the model. There are two noticeable features from Panel (B) in Table 4. Firstly, for stocks with high depths and narrow spreads such as Intel, inventory control and momentum chasing contribute comparably to the rationalization of pinging. This can be seen from the similar resulting pinging percentages produced by the model if either of the mechanism is shut down. Secondly, for stocks with low depths and wide spreads such as Amazon, momentum chasing carries more weight than inventory control in the rationalization of pinging. This is because the pinging percentage produced by the model decreases by a larger amount when the channel of price momentum is shut down than when the channel of hidden order is.

Finally,Table 4 shows that both the inventory control and the momentum chasing mechanisms are necessary and indispensable for rationalizing pinging activities, as the model can only captureless than $50\%$ of the pinging in the data if either mechanism is turned off

------------------------------------------------------------------

## 6.2Optimal Strategy Profiles

To further grasp the intuition behind the percentage attributions of the optimal HFT strategies for different stocks, I now show the detailed characterizations of the strategies in Figures 1 to 6 and present the economic rationales.The optimal HFT strategies depend on $t$ (time), $Y$ inventory $F$ depth imbalance and S (spread). Therefore, I will characterize the strategies as a function of $Y$ and $F$ ,for $S=\delta$ and $S=2\delta$ near $t=0$ and $t={^{\prime}}I$ .The optimal strategies are mostly time invariant if the value of $t$ is not extremely close to the terminal date $T$ .In addition,the strategy profiles for Qualcomm are not exhibited since they are in between the ones for Intel and the ones for Amazon.30

Figure 1 illustrates the optimalHFT strategies for Intel at $t=10$ with the inventory and the depth imbalance levels shown on the horizontal and the vertical axes respectively. Consider Figure 1(A) on the left first, where the spread $S=\delta$ .The central region of “market making" denotes submitting a limit order at both the best bid and ask prices. The two blue regions stand for inventory management: buy (sell) indicates using buy (sell) market orders to increase (decrease) the inventory towards zero. In particular, partial inventory control means unwinding the inventory partially, whereas inventory control means changing the inventory precisely back to zero.For instance, if the inventory is -5 lots, the strategy will specify purchasing $Z$ lots with $z<5$ in the region of partial inventory control (buy), yet it will specify buying exactly 5 lots in the region of inventory control (buy). The “momentum” area means utilizing market orders to change the inventory and set up a directional position: buy and sell denote establishing positive and negative positions respectively. For example, under momentum (buy), if the inventory is -5 lots, the strategy will dictate a purchase of $Z$ lots with $z>5$ , and if the inventory is 1 lot, the strategy will dictate a purchase of $Z$ lots with $z\geq1$ .Finally, there is no pinging since it is not possible to submit a limit order inside the spread when the spread is at its minimum level of $\delta$

------------------------------------------------------------------

The economic intuition behind Figure 1(A) is explained as follows. The situation where the depth imbalance $F\leq0$ will be focused on, since a similar but symmetrically reversed exposition can be applied to the opposite case where $F\geq0$ .Tobegin with,when the depth imbalance is mildly positive, the probability of a positive mid-price jump is somewhat higher than that of a negative one.If the HFT has a negative inventory, he will face an inventory risk as the mid-price is likely to move against his holdings. Thus he will reduce this risk via a market order.31 However,if the HFT holds a positive inventory, he would gain from a positive mid-price jump and thus do market making. Since a take strategy is expensive and the signal effect from the depth imbalance on the directional mid-price movement is not strong enough, the HFT would not use market orders to increase his positive inventory

Furthermore, when the depth imbalance becomes considerably more positive, the probability of a positive mid-price jump is much higher than that of a negative one. If the HFT has a negative inventory, he faces a substantial inventory risk, yet also a clear opportunity to chase the upward price momentum.Therefore, the HFT aggressively takes the liquidity from the market through buy market orders to establish a directional (positive）inventory position, which is the momentum (buy) region in the graph. However, the HFT stops chasing the price momentum if his inventory is rather positive. As the mid-price jump intensities of Intel are not very large, building a substantially positive inventory would result in a large inventory risk on the opposite side if the mid-price does not jump up soon enough.32

Next, consider Figure 1(B) on the right, where the spread is $2\delta$ . The green and yellow areas on each side of the market making region represent pinging strategies,which the majority of the graph consists of. Here,“pinging on the bid (ask) side” denotes submitting a buy (sell) limit order inside the spread at the best bid plus $\delta$ (best ask minus $\delta$ )，while

------------------------------------------------------------------

letting the sell (buy) limit order joining the queue at the best ask (best bid). To understand the intuition behind Figure 1(B) and compare it to the case of Figure 1(A), I will again concentrate on the scenario in which the depth imbalance is less than zero.

When the depth imbalance is modestly positive, if the HFT's inventory level is quite negative, he will remove the inventory risk by market orders.However,the inventory control is only partial since complete inventory controls are too costly under $S=2\delta$ . Alternatively, if the HFT's inventory level is closer to zero, he will instead use a pinging strategy from the bid side to reduce his inventory risk, for three reasons. Firstly, despite execution uncertainty, pinging is free. Since the inventory risk is small, it decreases the HFT's desire to use market orders. Secondly, a buy pinging order might hit a sell hidden order inside the spread. Thirdly, a positive depth imbalance implies a lower fill rate for queuing buy limit orders at the best bid, so that it is optimal for the HFT to jump the queue. On the other hand, if the HFT holds a significant level of positive inventory, he faces a large inventory risk due to the possibility of no upward price jump. Hence the HFT will ping on the ask side, which has a high chance of hitting a bid-side hidden order inside the spread and is costless.

When the depth imbalance is significantly positive, the HFT will reduce his inventory risk more aggressively by market orders if his inventory is below zero. However, if the inventory is positive but small, the HFT will pursue the price momentum by pinging on the bid side, which has a higher execution probability than submitting a buy limit order at the best bid. Chasing the momentum via a market order is suboptimal when $S=2\delta$ as the expected gain is less than the cost of using market orders. Thus the pinging strategies would serve two different purposes - unwinding the HFT's inventory or pursuing the price momentum

Next, Figure 2 shows the optimal HFT strategies for Intel at $T-3$ .Consider Figure 2(A) on the left first, with the spread $S=\delta$ .Since time $t$ is close to the terminal date, inventory management becomes a large concern for the HFT as he must liquidate all positions at $T$ .Therefore,if the HFT is holding a negative (positive) inventory and the mid-price is more likely to jump up (down）because of the positive (negative)depth imbalance,he

------------------------------------------------------------------

will aggressively unload his inventory through market orders to reduce the inventory risk. Conversely, when the HFT's inventory is in line with the likely price movement, he has an expected gain from holding a directional position. Hence the HFT will use a market-making strategy if his inventory and the depth imbalance are both positive (negative). In this case, it is not optimal for the HFT to use an aggressive momentum strategy to raise his directional positions, as inventory control is the prime objective when time approaches 7

Consider Figure 2(B) next. Similar to Figure 2(A), inventory management accounts for a large part of the optimal strategy profle, but there is only partial inventory control as market orders are very costly under $S=2\delta$ .Unlike in Figure 1(B), pinging strategies now have one sole objective: reducing the inventory risk. The HFT would only ping on the ask (bid) side if his inventory and the depth imbalance are both positive (negative), as pinging orders have a larger probability of executing against opposite-side hidden orders inside the spread and are free compared to market orders.

Let us now look at Figure 3, which compares the optimal strategy for Amazon (right) to that for Intel (left) in the case of time $t=10$ and spread $S=\delta$ .The major difference for Amazon is that the HFT takes liquidity a lot more often to carry out momentum strategies. The HFT is more aggressive since Amazon has much higher mid-price jump intensities as shown in Table 2.Thus the HFT is anticipating an upward (downward) directional price movement with a much larger likelihood if the depth imbalance is positive (negative), which causes the HFT to build a matching directional position via market orders. The expected reward of a price jump simply outweighs the cost of using market orders aggressively

Figure 4 contrasts the optimal strategy for Amazon (right）to that for Intel (left） in the case of time $t=10$ and spread $S=2\delta$ .There are two main changes on pinging strategies employed for Amazon. First, there is no pinging on the bid (ask) side when the HFT's inventory is negative (positive) and the depth imbalance is also moderately negative (positive). Second, pinging on the bid (ask) side is dominant when both the HFT's inventory and the depth imbalance are above (below)zero.These imply that when the HFT holds

------------------------------------------------------------------

a directional position in line with a likely mid-price move,his pinging strategies are used exclusively for chasing the price momentum. This is because Amazon has much higher midprice jump intensities so that the HFT can be more aggressive. Nevertheless, it is not optimal for the HFT to deploy momentum strategies via market orders as it is too expensive and the HFT already holds a favorable directional position. However, if the depth imbalance is extremely high, and the HFT holds an inventory position against the likely direction of the mid-price jump, the HFT would use momentum strategies in the case of Amazon (purple areas). The large cost of market orders is absorbed by the reduction in the inventory risk and the almost certain benefit from the anticipated price jump

Finally, Figure 5 and Figure 6 demonstrate the optimal HFT strategies for Amazon (right) towards the terminal date $T$ and compare them to those for Intel (left). The optimal strategies for the two cases are similar, despite the differences seen in Figure 3 and Figure 4 when $t<<T$ . Once more, this is because inventory management concerns are dominant as time approaches $T$ , so that pursuing the price momentum is no longer the HFT's objective.

## 6.3Auxiliary Predictions

Besides pinging rationalization, my model yields a couple of additional auxiliary predictions regarding pinging activities with respect to depth imbalances. They are shown below.

The first auxiliary prediction of the model is related to the directions of pinging activities. The model implies that if the HFT sees a positive (negative) depth imbalance and hence a positive (negative)price momentum more often, he is more likely to ping from the buy (sell) side and take positive (negative) directional bets due to momentum chasing motives. Consequently, it yields the following prediction

Prediction 1.There is more pinging from the buy (sell) side if the depth imbalance is more frequently positive (negative)

Now I check this prediction against data. To do this, I divide each trading day into

------------------------------------------------------------------

30-second intervals. 33 Next, I calculate the number of buy and sell pinging activities in each of these intervals in a similar manner to the computation of the number of pinging activities shown in Section 6.1.In addition,I also compute the durations (measured in seconds） of positive and negative imbalances in each interval.Then I use the following regression to measure and test the effect of imbalance durations on pinging activity directions

$$PO_t=\alpha+\beta DOI_t+x_t'\gamma+\epsilon_t.$$

$PO_{t}$ denotes the number of buy or sell pinging activities and $DOI_{t}$ the duration (measured in seconds) of positive or negative depth imbalances in the 30-second interval $t$ $t.\: x_{t}$ Ct ${\mathcal{L}}_{t}$ stands for other control variables which include $DOI_{t-1}$ ，the average spread and the volatility of the depth imbalance in the interval $t$ , and $tt$ is an error term.

The regression is performed separately for buy pinging activities on positive imbalances and sell pinging activities on negative imbalances, and across all trading days in June 2012. The final parameter estimates are calculated in the same way as in Table 2, i.e. time series averages of daily parameter estimates. Overall, I find that the parameter $\beta$ is statistically significant for all three types of stocks, with a value around 0.28 on average. This shows that the first auxiliary prediction is confirmed in the data.

The second auxiliary prediction of the model concerns the influence of depth imbalance volatilities on the frequencies of cancelled pinging activities. The model implies that If the momentum strengthens (imbalance widens) by a large amount, contemporaneously the HFT would cancel his pinging orders and use market orders instead to chase the momentum. And if the momentum weakens by a large amount or even reverses (imbalance reduces by a large amount or reverses), contemporaneously the HFT would also cancel his pinging orders as his pinging orders risk being adversely hit. This implication thus yields the following prediction:

Prediction 2.If the depth imbalance is more volatile,there should be more cancelled pinging 33The results are similar if I use 15-second or l-minute intervals instead of 30-second intervals.

------------------------------------------------------------------

activities occurring at the same time.

I employ a similar procedure as before to check this prediction, i.e. I divide each trading day into 30-second intervals and compute the number of cancelled pinging activities in each interval. Then I use the following regression to measure and test the effect of imbalance volatilities on cancelled pinging orders:

$$CPO_t=\alpha+\beta VOD_t+x_t'\gamma+\epsilon_t.$$

$CPO_{t}$ denotes the number of cancelled pinging orders and $VOD_{t}$ the log of the depth imbalance volatility in the 30-second interval $t$ 。iLt again stands for other control variables which include $VOD_{t-1}$ , the average spread and the number of market order arrivals in the interval $t$ , and $tt$ is an error term.

The regression is performed across all trading days in June 2012. The final parameter estimates are also calculated as the time series averages of daily parameter estimates. Overall, I find that the parameter $\beta$ is statistically significant for all three types of stocks as well. Nevertheless, the magnitude of $\beta$ is much higher for stocks with high depths and narrow spreads (with a value around 3.3) compared to stocks with low depths and wide spreads (with a value less than 1). Therefore, the result suggests that the second auxiliary prediction is by and large confirmed in the data too.

## 7Conclusion

In this paper, I build a continuous-time, partial equilibrium model on the optimal strategies of HFTs without any learning or manipulative ingredients to rationalize pinging activities observed in the data. I improve on the works of Ho and Stoll (1981) and Guilbaud and Pham (2013) by introducing hidden orders inside the bid-ask spread and short-term price momentum into my model. The HFT then uses pinging orders inside the spread to either control his inventory or chase price trends. I demonstrate that for stocks with high order book depths

------------------------------------------------------------------

and narrow spreads, pinging accounts for $20\%$ of the optimal strategies in the model,whereas this number goes up to $50\%$ for stocks with low order book depths and wide spreads. I then compare these pinging percentages from the model to their corresponding counterparts in the data, and find that over $70\%$ of the pinging activities in the data are captured by the model. The result thus suggests that most of the observable pinging activities from the data can be rationalized by my model

Furthermore,I show that for low-depth and wide-spread stocks, the majority of the pinging in the model occurs due to the momentum-chasing motive of the HFT. However, for high-depth and low-spread stocks, the inventory-control motive and the momentum-chasing motive of the HFT play similar roles in rationalizing pinging activities. In addition, I also develop a couple of other auxiliary predictions based on the model's implications. They are both assessed on and found to be consistent with the data in general. Therefore, my model gives the overall message that pinging activities do not necessarily have to be manipulative and can be mostly rationalized as part of the standard dynamic trading strategies of HFTs.

# 8Appendix

I show here the proofs for all lemmas and propositions, which are omitted in the paper.

Proof of Lemma 1:On one hand, I can show that the maximal value of (16） is smaller than that of (18). This is because, for any admissible strategy such that $Y_{T}=0$ we immediately obtain $Q(X_{T},Y_{T},P_{T},F_{T},S_{T})=X_{T}$ .On the other hand, given an arbitrary admissible strategy $\theta$ and its associated state variable processes $(X,Y,P,F,S)$ , I can consider an alternative strategy $\bar{\theta}$ , coinciding with. $\theta$ up to time $T$ and employing an market order that liquidates all the inventory $Y_{T}$ at the terminal date $T$ .The associated processes of the state variables $(X,Y,P,F,S)$ under $\ddot{\theta}$ satisfy $(X_{t},Y_{t},P_{t},F_{t},S_{t})\:=\:(X_{t},Y_{t},P_{t},F_{t},S_{t})$ for all $t<T$ , and $X_{T}=Q(X_{T},Y_{T},P_{T},F_{T},S_{T})$ ， $Y_{T}=0$ .Therefore, this shows that the maximal value of (18) is smaller than that of (16), hence (16) is equivalent to (18).

------------------------------------------------------------------

Proof ofLemma 2:The lower bound is obvious,since $V(t,x,y,p,f,s)=Q(x,y,p,f,s)$ by adopting the simple strategy that sets $\theta_{t}^{tk}=y$ and terminates the problem immediately at time $t$ .On the other hand, we have

$$\begin{aligned}&(x+py)+\sup_{\theta}\:\mathbb{E}_{t}\left[(X_{T}-x)+(P_{T}Y_{T}-py)-|Y_{T}|\Big(\frac{S_{T}}{2}-H_{T}+\epsilon\Big)-\gamma\int_{t}^{T}Y_{u-}^{2}d[P,P]\\&(x+py)+\sup_{\theta}\:\mathbb{E}_{t}\left[(X_{T}-x)+(P_{T}Y_{T}-py)-|Y_{T}|\Big(\frac{S_{T}}{2}-H_{T}+\epsilon\Big)\right]\:.\\&(x+py)+\sup_{\theta}\:\mathbb{E}_{t}\left[(X_{T}-x)+(P_{T}Y_{T}-py)-|Y_{T}|\Big(\frac{S_{T}}{2}-H_{T}+\epsilon\Big)\right].$$

Since all the jump intensities $(\lambda^{S},\lambda_{1,2}^{J},\lambda^{a},\lambda^{b})$ are finite constants, the term

$$\sup\limits_{\theta}\:\mathbb{E}_t\left[(X_T-x)+(P_TY_T-py)-|Y_T|\Big(\frac{S_T}{2}-H_T+\epsilon\Big)\right]$$

cannot be greater than the finite,maximum profit achievable through a combination of a make strategy that participates in every trade when market orders arrive (an upper bound on $X_{T}-x$ ,denoted by $C_{0}$ )and a directional, costless take strategy that bets on the mid-price jumps (an upper bound on $(P_{T}Y_{T}-py)-|Y_{T}|\left(\frac{S_{T}}{2}-H_{T}+\epsilon\right)$ , denoted by $C_{1}$ ).口

Proof of Lemma 3: As stated under (26)in the main paper, only the infinitesimal generators $\mathcal{L}^{P}$ ， $\mathcal{L}^{F}$ ， $\mathcal{L}^{S}$ )for the value function $V$ and the value of $\mathbb{E}_{t}d[P,P]_{t}$ require explicit expressions. They are given below

$$\begin{aligned}
\mathbb{E}_td[P,P]_t& =\left(\frac{1}{4}\lambda_{1}^{J}+\lambda_{2}^{J}\right)dt  \\
\mathcal{L}^{P}\circ V(t,x,y,p,f,s)& =\left(V\Big(t,x,y,p+\frac\delta2,f,s\Big)\psi_{1}(f)+V\Big(t,x,y,p-\frac\delta2,f,s\Big)(1-\psi_{1}(f))\right)  \\
&+\left(V(t,x,y,p+\delta,f,s)\psi_2(f)+V(t,x,y,p-\delta,f,s)(1-\psi_2(f))\right) \\
\mathcal{L}^{F}\circ V(t,x,y,p,f,s)& =V_{f}(\alpha_{F}f)dt+\frac{1}{2}V_{ff}\sigma_{F}^{2}dt  \\
\mathcal{L}^{S}\circ V(t,x,y,p,f,s)& =\bigg(\sum_{j=1}^{3}\rho_{ij}[V(t,x,y,p,f,j\delta)-V(t,x,y,p,f,i\delta)]\bigg)\lambda^{S}dt\:, 
\end{aligned}$$

where $Vf$ and $V_{ff}$ are the first and second order partial derivatives of $V$ against the state
$$\mathbb{E}_tdP_t=\bigg(\lambda_1^J\frac{\delta}{2}(2\psi_1(F_t)-1)+\lambda_2^J\delta(2\psi_2(F_t)-1)\bigg)dt.\quad\square $$

------------------------------------------------------------------

Proof of Proposition 1:To prove Proposition 1,I need to show that the value function $V$ in (19) is the unique viscosity solution to (25） and (26). Since I have established the necessary growth (boundness) conditions on $V$ that are shown in Lemma 2, the proposition - the existence and the uniqueness of the viscosity solution $V$ (a.k.a. the value function) is then a direct application of standard arguments and results from stochastic control theory, e.g., Oksendal and Sulem (2007), Chapters 9 and 10.

Proof of Lemma 4: It is clear that the quasi-variational inequality (28) and the terminal condition (29) are simplified versions of (25) and (26), if I can decompose the value function $V(t,x,y,p,f,s)$ as $x\:+\:py\:+\:\nu(t,y,f,s)$ .The required decomposition can be established by first noting that the mid-price $P$ has constant jump intensities and jump size distributions depending only on the state variable $F$ , and then extending to my scenario the argument for a simpler case shown in Guilbaud and Pham (2013).

Proof of Proposition 2:I prove Proposition 2 by first establishing three properties for my numerical scheme and then applying the theorem from Barles and Souganidis (1991)

Lemma. (Monotonicity))

For any $\Delta_{T}>0$ such that $\Delta_{T}\leq\left(\lambda^{S}+(\pi_{1}+(1-\pi_{1})\lambda^{a})+(\pi_{1}+(1-\pi_{1})\lambda^{b})\right)^{-1}$ , the operato $\mathcal{A}$ defined in equation (34)of the numerical scheme is non-decreasing in $\phi$ ,i.e

$$if\:\phi<\tilde{\phi},\:then\:\mathcal{A}(t,y,f,s,\phi)\leq\mathcal{A}(t,y,f,s,\tilde{\phi}),\:\forall t,\:y,\:s\:and\:f\:.$$

Proof. From the expression in equation (35) of the numerical scheme, it is clear that $g^{a}(f,s,\theta_{t}^{mk,b})<\pi_{1}+(1-\pi_{1})\lambda^{a}$ ,Vf, s, $\theta_{t}^{mk,b}$ , and $g^{b}(f,s,\theta_{t}^{mk,a})<\pi_{1}+(1-\pi_{1})\lambda^{b}$ , Vf, s, $\theta_{t}^{mk,a}$ Thus $1-\Delta_{T}\lambda^{S}-\Delta_{T}g^{a}(f,s,\theta_{t}^{mk,b})-\Delta_{T}g^{b}(f,s,\theta_{t}^{mk,a})>0$ as long as I choose the time grid
$$\Delta_{T}\leq\left(\lambda^{S}+(\pi_{1}+(1-\pi_{1})\lambda^{a})+(\pi_{1}+(1-\pi_{1})\lambda^{b})\right)^{-1}<\left(\lambda^{S}+g^{a}(f,s,\theta_{t}^{mk,b})\right)$$
$g^{b}(f,s,\theta_{t}^{mk,a})\Big)^{-1}$ , which implies that ${\bar{\mathcal{L}}}(t,y,f,s,\phi)$ is monotone in $\phi$ (as the sum of coefficients in front of $\phi$ is positive)and so is $\mathcal{A}(t,y,f,s,\phi)$ ： $L$

Lemma. (Stability)

------------------------------------------------------------------

For any $\Delta_{T},\Delta_{Y},M_{Y},\Delta_{F},M_{F}\:>\:0$ ，there ezists aunique solution $UU$ to (37)-(38),and the sequence $\{\varpi\}$ is uniformly bounded

Proof. By the definition of the backward scheme (37)-(38), the solution $UU$ exists and is unique. The uniform bound follows from the growth condition (lower and upper bounds) on the reduced-form value function $V$ (a modification on Lemma 2,i.e.the bounds on $V$ ).口

Lemma.(Consistency)

The scheme (37)-(38)is consistent, i.e.for all $(t,y,f)\in[0,T)\times\mathbb{R}\times\mathbb{R}$ and any smoothtest function $\phi$ ，Qs $(\Delta_{T},\Delta_{Y},M_{Y},\Delta_{F},M_{F})\to(0,0,\infty,0,\infty)$ ，and $(t^{\prime},y^{\prime},f^{\prime})\to(t,y,f)$

$$\begin{aligned}
&\operatorname*{lim}\:\frac{1}{\Delta_{T}}[\widetilde{\mathcal{L}}(t^{\prime}+\Delta_{T},y^{\prime},f^{\prime},s,\phi)-\phi(t^{\prime},y^{\prime},f^{\prime},s)] \\
&=\frac{\partial\phi}{\partial t}+y\frac{\mathbb{E}_{t}dP_{t}}{dt}+\mathcal{L}^{\mathcal{F}}\circ\phi+\mathcal{L}^{\mathcal{S}}\circ\phi-\gamma y^{2}\frac{\mathbb{E}_{t}d[P,P]_{t}}{dt}+ \\
&\sup_{\theta^{mk}}\left\{g^{a}(f,s,\theta_{t}^{mk,b})\cdot\left(\phi(t,y+1,f,s)-\phi(t,y,f,s)+s/2-\delta\theta_{t}^{mk,b}\right)+\right\} \\
&g^{b}(f,s,\theta_{t}^{mk,a})\cdot\left(\phi(t,y-1,f,s)-\phi(t,y,f,s)+s/2-\delta\theta_{t}^{mk,a}\right)
\end{aligned}$$

and

$$\mathrm{m}\:\widetilde{\mathcal{M}}\circ\widetilde{\mathcal{L}}(t^{\prime},y^{\prime},f^{\prime},s,\phi)=\operatorname*{sup}_{\zeta}\left\{\phi(t,y+\zeta,f,s)-|\zeta|(s/2+\epsilon)+|y|\int_{H}H\:dG(H\:|\:s,f)\right\}$$

Proof. This follows from the result in Section 6.1.2 of Chen and Forsyth (2008).

Proposition. (Convergence) The solution $W$ to the numerical scheme of (37)-(38）and the corresponding discretized policy functions converge locally uniformly to the reduced-form. value function $V$ and the equilibrium optimal strategies respectively on $[0,T]\times\mathbb{R}\times\mathbb{R}$ a.S $(\Delta_{T},\Delta_{Y},M_{Y},\Delta_{F},M_{F})\to(0,0,\infty,0,\infty),\:\forall s\in\mathcal{S}.$

Proof. Given the properties of monotonicity, stability and consistency of the numerical scheme, this is a direct application of the result of Barles and Souganidis (1991).

------------------------------------------------------------------

# References

Ait-Sahalia, Y., 1999, "Transition densities for interest rate and other nonlinear diffusions, Journal of Finance, 54, 1361-1395

Ait-Sahalia, Y., and P. A. Mykland, 2003,The effects of random and discrete sampling when estimating continuous-time diffusions," Econometrica, 71, 483-549

Avellaneda, M., and S. Stoikov, 2008,“High-frequency trading in a limit order book,” Quantitative Finance, 8, 217-224.

Barles, G., and P. E. Souganidis, 1991, “Convergence of approximation schemes for fully nonlinear second order equations," Asymptotic Analysis, 4, 271-283

Baron, M., J. Brogaard, and A. A. Kirilenko, 2014, “Risk and return in high frequency trading," Working paper, available at SSRN: http://papers.ssrn.com/abstract=2433118.

Baruch, S., and L. R. Glosten, 2013, Flickering quotes," Working paper, available at the following address: https://www0.gsb.columbia.edu/faculty/lglosten/papers/. Baruch-Glosten-Flickering-Quotes-final.pdf.

Brogaard, J., B. Hagstromer, L. L. Norden, and R. Riordan, 2014, “Trading fast and slow Colocation and market quality," Working paper, available at SSRN: http://papers.. ssrn.com/abstract=2317797.

Brogaard, J., T. Hendershott, and R. Riordan, 2014, High-frequency trading and price discovery,"Review of Financial Studies, 27, 2267-2306

Buti, S., and B. Rindi, 2013, *"Undisclosed orders and optimal submission strategies in a limit order market," Journal of Financial Economics, 109, 797-812.

Chen, Z., and P. A. Forsyth, 2008,“"A numerical scheme for the impulse control formulation for pricing variable annuities with a guaranteed minimum withdrawal benefit (GMWB), Numerische Mathematik, 109(4),535-569

------------------------------------------------------------------

Cont, R., and E. Voltchkova, 2005,“A finite difference scheme for option pricing in jump diffusion and exponential Levy models,” SIAM Journal on Numerical Analysis, 43(4) 1596-1626.

Crandall, M. G., H. Ishii, and P.-L. Lions, 1992, "User's guide to viscosity solutions of second order partial differential equations," Bullletin of the American Mathematical Society, 27, 1-67.

Crandall, M. G., and P.-L. Lions, 1983, “Viscosity solutions of Hamilton-Jacobi equations, Transactions of the American Mathematical Society, 277, 1-42

Easley, D., M. Lopez de Prado, and M. O'Hara, 2011, “The microstructure of the "Flash Crash": Flow toxicity, liquidity crashes, and the probability of informed trading," Journa of Portfolio Management, 37(2),118-128.

Fleming, W. H., and H. M. Soner, 2o05, Controlled markov processes and viscosity solutions. Springer, New York, 2nd edn. Gould, M. D., M.A.Porter, S.Williams, M. McDonald, D. J. Fenn, and S. D. Howison 2013, Limit order books," Quantitative Finance, 13, 1709-1742. Guilbaud, F.,and H. Pham,2013, “Optimal high-frequency trading with limit and market orders,Quantitative Finance,13, 79-94 Hagstromer, B., and L. L. Norden, 2013, "The diversity of high-frequency traders, Journa. of Financial Markets,16, 741-770 Hasbrouck, J., and G. Saar, 2009, "Technology and liquidity provision: The blurring of traditional definitions, Journal of Financial Markets, 12, 143-172. 2013, Low-latency trading, Journal of Financial Markets, 16, 646-679

------------------------------------------------------------------

Hautsch, N., and R. Huang, 2012a,“Limit order fow, market impact, and optimal order sizes: Evidence from NASDAQ TotalView-ITCH data, in Market Microstructure: Confronting Many Viewpoints. Wiley, United Kingdom, pp. 137-161

Hautsch, N., and R.Huang, 2012b, “On the dark side of the market: Identifying and analyzing hidden order placements,” Working paper, available at SSRN: http: //papers.ssrn. com/sol3/papers.cfm?abstract\_id=2004231.

Hendershott, T., C. M. Jones, and A. J. Menkveld, 2011, “Does algorithmic trading improve liquidity?," Journal of Finance, 66, 1-33

Hendershott, T., and R. Riordan, 2013, "Algorithmic trading and the market for liquidity, Journal of Financial and Quantitative Analysis, 48, 1001-1024

Hirschey, N., 2013, “Do high-frequency traders anticipate buying and selling pressure?, Working paper, available at SSRN: http://ssrn.com/abstract=2238516.

Ho, T., and H. R. Stoll, 1981, “Optimal dealer pricing under transactions and return uncertainty," Journal of Financial Economics, 9, 47-73.

Karr, A., 1991, Point processes and their statistical inference. CRC / Marcel Dekker, Inc. New York, 2nd edn.

Kirilenko, A. A., A. S. Kyle, M. Samadi, and T. Tuzun, 2014, "The Flash Crash: The impact of high frequency trading on an electronic market,” Working paper, available at SSRN: http://papers.ssrn.com/abstract=1686004

Lewis, M., 2014, Flash Boys: A Wall Street Revolt. W. W.Norton & Company, New York

Menkveld, A. J., 2013,“High frequency trading and the new market makers,” Journal of Financial Markets, 16, 712-740

ksendal, B., and A. Sulem, 2007, Applied stochastic control of jump diffusions. Springer New York, 2nd edn.

------------------------------------------------------------------

## Table 1:Estimated Model Parameters and Fixed Parameters

Panel (A) of this table summarizes the model parameters to be estimated that govern the exogenous evolutions of the limit order book variables, as well as their respective estimation procedures. S stands for the bid-ask spread, $F$ for the depth imbalance at the best quotes, and $P$ for the mid-price. Prob. is an abbreviation for the word probability. The estimates of these parameters are reported in Table 2. Panel (B) of this table depicts the values of the fixed, non-estimated parameters that are used in my numerical analysis of the optimal HFT strategies. The $\$0.003$ per share fee for market orders corresponds to the same transaction fee stated by NASDAQ for its stocks.Furthermore, the tick size $\delta$ is set to be S0.01 for Intel and Qualcomm, which is the tick size for all NASDAQ stocks that have prices above 81 .For Amazon, the tick size is set to be $\$0.1$ ,and the reason is given in Table 2. The word MC stands for Monte Carlo.

| Parameter | Definition | Estimation Procedure |
|-----------|------------|----------------------|
| λ^S, ρ    | Jump intensity and transition matrix of S | Non-parametric estimators |
| α_F, σ_F  | Mean-reversion and volatility parameters of F | Maximum likelihood |
| λ_1,2     | Jump intensities of P | Non-parametric estimators |
| β_1,2     | Prob. distribution parameters of directions of P jumps | Logistic regressions |
| κ, π_1,2  | Prob. distribution parameters of hidden orders | Logistic regressions |
| λ_a, λ_b  | Exogenous sell (a) and buy (b) market order arrival intensities | Non-parametric estimators |
| s_0,1     | Parameters of limit order fill rates when hit by market orders | Logistic regressions |

Panel (B): Fixed parameters

| Parameter type | Parameter | Description | Value |
|----------------|-----------|-------------|-------|
| Discretization and localization parameters | $T$ | Time length in seconds | 3600 |
| | $\Delta T$ | Size of time step in seconds | 0.5 |
| | $M_Y$ | Inventory grid bound (in lot) | 30 |
| | $\Delta Y$ | Inventory grid step size (in lot) | 1 |
| | $M_F$ | Depth imbalance grid bound | 10 |
| | $\Delta F$ | Depth imbalance grid step size | 0.01 |
| Model constants | $\delta$ | Tick size | 0.01 |
| | $\epsilon$ | Per share fee | 0.003 |
| | $\gamma$ | Inventory penalization | 2 |
| | $\zeta_{max}$ | Max market order size (in lot) | 10 |
| Simulation parameters | $N_MC$ | Number of MC simulation paths | 10000 |
| | $X_0, Y_0$ | Initial cash and inventory of HFT | 0 |
| | $P_0$ | Initial mid-price of stock | 10 |

------------------------------------------------------------------

### Table 2:Estimates of Limit Order BookParameters

This table shows the average values of the daily estimates of the limit order book parameters in the month of June 2012 for the three representative stocks Intel (INTC), Qualcomm (QCOM) and Amazon (AMZN),using order book data reconstructed from NASDAQ TotalView-ITCH 4.0 message feeds.Newey-West HAC standard errors are in parentheses. Standard errors of the transition matrix $\mu$ estimates are not shown as they are close to zero. Intensity parameters are all measurec at per second frequency. In addition,I normalize the tick size $\delta$ tobe $\$0.1$ for Amazon, since on average, the spread and limit order prices of Amazon tend to be in multiples of $\$0.1$ instead of the minimum tick size S0.01 used for Intel and Qualcomm. For definitions of all the parameters, please refer to Table 1.

| Spread | λ^s | INT | C   | AMZN |
|--------|-----|-----|-----|------|
|        |     | 0.161/s (0.010) | 0.312/s (0.017) | 0.578/s (0.027) |
| ρ      |     | 0.99 0.01 0.00 | 0.95 0.05 0.00 | 0.222 0.743 0.257 |
| Imbalance | α_F | 0.308 (0.016) | 0.547 (0.027) | 0.734 (0.035) |
|         | σ_F | 0.777 (0.029) | 1.429 (0.033) | 2.336 (0.074) |
| Mid-price | λ_i | 0.161/s (0.010) | 0.307/s (0.018) | 0.522/s (0.027) |
|         | β_1 | 2.744 (0.077) | 2.651 (0.076) | 2.610 (0.075) |
|         | λ_j | 0.052/s (0.003) | 0.075/s (0.005) | 0.121/s (0.007) |
|         | β_2 | 4.766 (0.244) | 2.921 (0.257) | 1.881 (0.129) |
| Hidden order | κ | 1.196 (0.034) | 1.036 (0.030) | 0.992 (0.021) |
|         | π_1 | 0.238 (0.010) | 0.233 (0.010) | 0.230 (0.009) |
|         | π_2 | 0.125 (0.006) | 0.117 (0.006) | 0.114 (0.006) |
| Market order | λ^a | 0.110/s (0.006) | 0.130/s (0.006) | 0.181/s (0.012) |
|         | λ^b | 0.110/s (0.004) | 0.130/s (0.006) | 0.179/s (0.010) |
| Fill rate | s_0 | 1.320 (0.039) | 1.454 (0.055) | 1.648 (0.066) |
|         | s_1 | 0.399 (0.019) | 0.462 (0.022) | 0.673 (0.031) |

------------------------------------------------------------------

### Table 3:Percentage Breakdown of the Optimal HFT Strategies

The table reports, for the three representative stocks Intel (INTC), Qualcomm (QCOM) and Amazon (AMZN), the percentage attributions (averaged over simulations) of the optimal HFT strategies to three types of activity: traditional market making & inventory control, pinging,and momentum (directional) trading via market orders. For the explanation on how these percentage attributions are obtained, please refer to Section 6.1 in the main article

INTC QCOM AMZN
Traditional market making & Inventory control 70.5% 58.3% 31.8%
Pinging 19.7% 28.1% 46.7%
Momentum trading via market orders 9.8% 13.6% 21.5%

## Table 4: Model's Pinging v.s. Data's Pinging

This table compares the pinging percentages (pinging as a percentage of all limit order book activities) obtained from the model to the pinging percentages observable from the data for three representative firms: Intel (INTC), Qualcomm (QCOM), and Amazon (AMZN). In order to illustrate how pinging is rationalized by the model (i.e. the % of data that are pinged as captured by the model). Panel A reports the pinging percentages produced by the model when one or more of the limit order book features are eliminated, as shown in Table 3. These are expressed as a fraction of the pinging percentage observed in the data which is the percentage of a firm's pinging captured by the model. Panel B breaks down the pinging produced by the model when one or more of the limit order book features are eliminated, as shown in Table 3. These are expressed as a fraction of the pinging percentage observed in the data which is the percentage of a firm's pinging captured by the model. No hidden orders means the existence probabilities of the hidden orders in the model are set to zero, i.e., the parameters π1 and π2 are fixed at zero. No price momentum means the depth imbalance F of the limit order book does not have a predictive power for the directions of mid-price jumps in the model, i.e., the parameters β1 and β2 are set to zero, which implies that the mid-price has equal probabilities of moving up or down. For the detailed explanation on how pinging percentages from the data are calculated, please refer to Section 6.1 in the main article.

Panel (A): Pinging percentages from the model and the data

|  | INTC | QCOM | AMZN |
| --- | --- | --- | --- |
| Pinging percentage produced by model | 19.7% | 28.1% | 46.7% |
| Pinging percentage observed in data | 23% | 39% | 70% |
| Percentage of data's pinging captured by model | 86% | 72% | 67% |

Panel (B): Further breakdown on pinging percentages from the model

|  | INTC | QCOM | AMZN |
| --- | --- | --- | --- |
| Model's pinging percentage, no hidden orders | 8% | 15% | 31% |
| Model's pinging percentage, no price momentum | 12% | 13% | 16% |

------------------------------------------------------------------

The figure shows the HFT strategy profile for line $t=10$ with the spread $S$ equal to $10$ at time $t$ (INTC) and to $9$ at time $t=11$. The optimal inventory and the depth imbalance levels are shown on the horizontal and the vertical axes respectively. The optimal strategy is computed using the numerical scheme (38), using the numerical scheme (37). The figure shows the HFT's inventory and the depth imbalance levels as a function of my inputs in Table A.2. The strategy is stated in the figure.

![](https://storage.simpletex.cn/view/fHnxcAGug1iwC1BR6D1h9ywzZ8S7uIysD)

![](https://storage.simpletex.cn/view/f2gA4413ycLahdh8aNEfTZMFWAiYFeNIu)

------------------------------------------------------------------

![](https://storage.simpletex.cn/view/fvX3phnDuDUoN462qY3gNCIn3mKhoIyXl)

This figure shows the optimal inventory profile for HFT strategy at time $t = T - 3$, with the speed imbalance $S$ equal to $\delta$ (INTC) at time $T - 3$, each colored region represents a particular type of HFT panel. For given values of the inventory level and the depth of the market order book, each colored region represents a limit bid and ask orders at both the best bid and ask prices, which is stated in the figure. Specifically, **market making**, **buy** and **sell** indicate the strategy of submitting partially a buy or sell order using the inventory control to increase or decrease the inventory back to zero, respectively. Using market orders precisely means buying or selling all orders at the best bid or ask price. **Punging on the bid side**, the strategy is to submit a buy order at the best bid price at the right panel stands minus $\delta$ (best buy). While punging on the ask side**, while punging the spread at the quote joining the buy order at the best bid (best ask).

![](https://storage.simpletex.cn/view/fwYFThOsrzn8UwKAmQ3b7WZQpmkNKFHYv)

------------------------------------------------------------------

$\begin{array}{ccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccc$

------------------------------------------------------------------

![](https://storage.simpletex.cn/view/fdHuqnweTqmS40fdBtyqf8AcWc636VN7l)

O
This figure compares the optimal HFT profile for Amazon (AMZN) with that for Intel (INTC), right panel, at time $t=10$ with the speed $S$ equal to 20. For given imbalance and the depth values of a colored region repeats a particular type of HFT strategy, which is stated in the figure. Specifically, **smart making** means the strategy of submitting a limit order to unwind the inventory partially using market orders (sell). Partially unwinding the inventory control back to zero or to decrease the inventory precisely uses buy orders (**momentum**) and sell orders respectively. In both the bid and ask prices, the strategy of utilizing market positions of establishing directional positions of holding positions of inventory respectively set up a directional position, i.e., increase (decrease) the inventory.

![](https://storage.simpletex.cn/view/f2SPfAbURWUvtyZivngBQ9oheGcMshmwG)

------------------------------------------------------------------

![](https://storage.simpletex.cn/view/fZEnZodtprUZskUMnekssVFxct4w45aWp)

This figure compares the optimal HFT strategy for Amazon (AMZN) with the spread of the inventory profile. Specifically, the strategy of submitting a limit order at time $t=7$ with the death imbalance level of the inventory profile represents a particular type of HFT strategy which is stated in the figure. For example, 'market making' means partially unwinding the inventory control using buy orders to zero whereas 'partial inventory control' means using market orders to change the inventory precisely back to zero. The inventory profile for Amazon (AMZN), right panel, each colored region repeats the same pattern as in the left panel and the values of the inventory profile are given in the figure. The spread is defined as $\Delta_{t}=3-2\cdot I_{t}$ where $I_t$ indicates the inventory.

------------------------------------------------------------------

![](https://storage.simpletex.cn/view/fHP3srxKTgBLztiEKA0CL5G0Lowz3VN8l)

This figure compares the optimal HFT strategy profile for Intel (INTC, left panel) with that for Amazon (AMZN, right panel) at time $t = T - 3$, with spread $S$ equal to $20^{\circ}$. For given values of the inventory level and the depth imbalance, each colored region represents a particular type of HFT strategy, as stated in the figure. "Mkt MKP" in both panels stands for market making. Specifically, "market making" is the strategy of submitting a limit order at both the best bid and ask prices. "Partial inventory control" means using market orders to unwind (decrease) the inventory. "Pinging on the bid/ask side" is the strategy of aligning a buy (sell) limit order inside the quote at the best bid plus $\delta$ (best ask minus $\delta$), while letting the sell (buy) order join the queue at the best price.
